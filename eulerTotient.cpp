
long long eulerTotient(long long n){
	long long res = n; 
	for (long long i = 2; i * i <= n; i++){
		if (n % i == 0){
			// i is the smallest prime of n ;
			while (n % i == 0) n = n / i; 
			res -= res / i; 
		}
	}

	if (n > 1){
		res -= res / n; 
	}

	return res; 
}

vector<ll> eulerTotientRange(ll n){
	vector<ll> ans(n + 1);
	
	for (int i = 1; i <= n; i++){
		ans[i] = i; 
	}

	for (int i = 2; i <= n; i++){
		for (int j = i; j <= n; j+=i){
			ans[j] -= ans[j]/i; 
		}
	}

	return ans; 
}
