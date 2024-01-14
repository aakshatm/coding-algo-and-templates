#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, s, e) for (int i = (s); i < (e); i++)
#define rrep(i, s, e) for (int i = (s); i >= (e); i--)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<long long> vll;
typedef pair<long long,long long> pll; 
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcd(ll a, ll b){
	if (b == 0) return a; 
	return gcd(b, a % b); 
}
ll lcm(ll a, ll b){
	return (a * b)/gcd(a, b);
}

ll pow(ll x, ll n, ll mod){
	ll ans = 1; 
	while (n > 0){
		if (n & 1){
			ans *= x; 
			ans %= mod; 
			n--; 
		}

		x = (x * x) % mod; 
		n = n / 2;
	}

	return ans;
}

class SegmentTree{
public: 
	vector<ll> seg; 
	int n;
	SegmentTree(int n, vector<int>&arr){
		this -> n = n; 
		seg.resize(4 * n);
		build(0, 0, n - 1, arr);
	}

	ll merge(ll left, ll right){
		return left + right; 
	}

	void build(int ind, int low, int high, vector<int>&arr){
		if (low == high){
			seg[ind] = arr[low];
			return ;
		}
		int mid = (low + high) >> 1; 
		build(ind * 2 + 1, low, mid, arr);
		build(ind * 2 + 2, mid + 1, high, arr);
		seg[ind] = merge(seg[ind * 2 + 1], seg[ind * 2 + 2]);
	}

	void update(int i, int val){
		update(0, 0, n - 1, i, val);
	}

	void update(int ind, int low, int high, int i, int val){
		if (low == high){
			seg[ind] = val; 
			return ;
		}
		int mid = (low + high) >> 1; 
		if (i <= mid) update(ind * 2 + 1, low, mid, i, val);
		else update(ind * 2 + 2, mid + 1, high, i, val);
		seg[ind] = merge(seg[ind * 2 + 1], seg[ind * 2 + 2]);
	}

	ll query(int ind, int low, int high, int l, int r){
		// no overlaop low high l r l r low high
		if (low > r || l > high){
			return 0; 
		}

		// complete 
		// l low high r
		if (low >= l && high <= r){
			return seg[ind];
		}
		int mid = (low + high) >> 1; 
		ll leftans = query(ind * 2 + 1, low, mid, l, r);
		ll rightans = query(ind * 2 + 2, mid + 1, high, l, r);

		return merge(leftans, rightans);
	}


	int greaterThanEqual(int ind, int low, int high, long long val){
		if (low == high){
			return (val <= seg[ind] ? low : -1); 
		}
		int mid = (low + high) >> 1; 
		if (seg[ind * 2 + 1] < val){
			return greaterThanEqual(ind * 2 + 2, mid + 1, high, val - seg[ind * 2 + 1]); 
		}else{
			return greaterThanEqual(ind * 2 + 1, low, mid, val);
		}
	}

	int greaterThanEqual(ll val){
		return greaterThanEqual(0, 0, n - 1, val);
	}
};





void solve(){
	// 2 types of queries
	// 1. find the index where the prefix sum becomes greater than equal to x 
	// 2. update the index with val x

	vi arr = {1, 4, 2, 1, 2, 3, 0, 4};
	int n = arr.size(); 

	SegmentTree st(n, arr);
	// st.update(0, 2);
	cout << st.greaterThanEqual(9) << endl ;


}


int main() {
	fastio(); 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1; 
	// cin >> t; 
	while (t--){
		solve(); 
	}
	
}
