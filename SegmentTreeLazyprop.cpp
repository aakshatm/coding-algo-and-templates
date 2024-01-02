
class SegmentTree{

public: 
	vector<int> seg; 
	vector<int> lazy; 
	SegmentTree(int n, vector<int>&arr){
		seg.resize(4*n, 0);
		lazy.resize(4*n, 0);
		build(0, n - 1, 0, arr);
	}	

	void build(int low, int high, int ind, vector<int>&arr){
		if (low == high){
			seg[ind] = arr[low];
			return; 
		}

		int mid = (low + high) >> 1; 
		build(low, mid, ind * 2 + 1, arr); 
		build(mid + 1, high, ind * 2 + 2, arr); 
		seg[ind] = seg[ind*2 + 1] + seg[ind * 2 + 2];
	}

	void update(int low, int high, int ind, int l, int r, int val){
		// lazy propogation
		if (lazy[ind] != 0){
			seg[ind] += lazy[ind] * (high - low + 1);
			// niche propogate kardo to children
			if (low != high){
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0; 
		}

		// no overlap
		// l r low high || low high l r
		if (low > r || l > high){
			return ;
		}

		// full overlap
		// l low high r
		if (low >= l && high <= r){
			// update kar do 
			seg[ind] += val * (high - low + 1);
			// niche propogate kardo updates
			if (low != high){
				lazy[ind * 2 + 1] += val ;
				lazy[ind * 2 + 2] += val ;
			}
			return ;
		} 


		// partial overlap
		int mid = (low + high) >> 1; 
		update(low, mid, ind * 2 + 1, l, r, val);
		update(mid + 1, high, ind * 2 + 2, l, r, val);
		seg[ind] = seg[ind * 2 + 1] + seg[ind* 2 + 2];

	}

	int query(int low, int high, int ind, int l, int r){
		// lazy propogation
		if (lazy[ind] != 0){
			seg[ind] += lazy[ind] * (high - low + 1);
			// niche propogate kardo to children
			if (low != high){
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0; 
		}

		// no overlap
		// l r low high || low high l r
		if (low > r || l > high){
			return 0;
		}

		// full overlap
		// l low high r
		if (low >= l && high <= r){
			return seg[ind];
		} 

		// partial overlap
		int mid = (low + high) >> 1; 
		int leftAns = query(low, mid, ind * 2 + 1, l, r);
		int rightAns = query(mid + 1, high, ind * 2 + 2, l, r);
		return leftAns + rightAns; 
	}

};
