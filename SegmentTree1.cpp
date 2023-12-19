class SegmentTree{
	vector<int> seg; 
public: 
	SegmentTree(int n, int arr[]){
		seg.resize(4*n);
		build(0, 0, n - 1, arr);
	}


	void build(int ind, int left, int right, int arr[]){
		if (left == right){
			seg[ind] = arr[left];
			return; 
		}

		int mid = (left + right) / 2; 
		build(2*ind + 1, left, mid, arr);
		build(2*ind + 2, mid + 1, right, arr);
		seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);

	}

	void update(int i, int val, int ind, int left, int right){
		if (left == right){
			seg[ind] = val; 
			return ; 
		}
		int mid = (left + right) / 2; 
		if (i <= mid){
			update(i, val, ind * 2 + 1, left, mid);
		}else{
			update(i, val, ind * 2 + 2, mid + 1, right);
		}
		seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r){
		// [low high] l r 	[l r] low high // no overlap
		if (l > high || low > r){
			return INT_MAX; 
		}

		// [l low high r] // total overlap
		if (low >= l && high <= r){
			return seg[ind];
		}

		// partial 
		int mid = (low + high) / 2; 
		int leftAns = query(ind * 2 + 1, low, mid, l, r);
		int rightAns = query(ind * 2 + 2, mid + 1, high, l, r);
		return min(leftAns, rightAns);
	}

};
