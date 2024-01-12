class SegmentTree{
	int n; 
	vector<int> tree; 
public: 
	SegmentTree(int n, vector<int>& arr){
		tree.resize(4*n);
		this -> n = n; 

		build(0, n - 1, 0, arr);
	}

	void build(int low, int high, int ind, vector<int>&arr){
		if (low == high){
			tree[ind] = arr[low];
			return; 
		}
		int mid = (low + high) >> 1; 
		build(low, mid, ind * 2 + 1, arr);
		build(mid + 1, high, ind * 2 + 2, arr);
		tree[ind] = min(tree[ind * 2 + 1], tree[ind * 2 + 2]); 
	}

	int query(int l, int r){
		return query(0, n - 1, 0, l, r);
	}

	void update(int i, int val){
		update(0, n - 1, 0, i, val);
	}

private: 
	int query(int low, int high, int ind, int l, int r){
		// no over lap
		// [l r] low high , low high l r
		if (low > r || l > high){
			return INT_MAX; 
		}
		// total overlap
		// l low high r
		if (low >= l && high <= r){
			return tree[ind];
		}
		// partial overlap
		// [ l ...low h  high]
		int mid = (low + high) >> 1; 
		int left = query(low, mid, ind * 2 + 1, l, r);
		int right = query(mid + 1, high, ind * 2 + 2, l, r);
		return min(left, right);
	}

	void update(int low, int high, int ind, int i, int val){
		if (low == high){
			tree[ind] = val ;
			return; 
		}

		int mid = (low + high) >> 1; 
		if (i <= mid){
			update(low, mid, ind * 2 + 1, i, val);
		}else{
			update(mid + 1, high, ind * 2 + 2, i, val);
		}
		tree[ind] = min(tree[ind * 2 + 1], tree[ind * 2 + 2]);
	}
};
