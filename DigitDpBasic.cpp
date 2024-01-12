int mod = 1e9 + 7; 
int dp[23][2][401];
long long solve(string &str, int &minSum, int &maxSum, int pos = 0 , bool bound = true, int sum = 0){
    if (sum > maxSum) return 0; 
    if (pos == str.size()){
        if (sum >= minSum){
            return 1; 
        }
        return 0 ; 
    }

    if (dp[pos][bound][sum] != -1) return dp[pos][bound][sum];

    int maxDigit = 9; 
    if (bound){
        maxDigit = str[pos] - '0';
    }
    long long ways = 0; 

    for (int d = 0; d <= maxDigit; d++){
        ways += solve(str, minSum, maxSum, pos + 1, (bound & (d == (str[pos] - '0'))), sum + d);
        ways %= mod; 
    }

    return dp[pos][bound][sum] = ways; 


}

int count(string num1, string num2, int min_sum, int max_sum) {
  
    memset(dp, -1, sizeof(dp));
    long long rightAns = solve(num2, min_sum, max_sum);
    memset(dp, -1, sizeof(dp)); 
    long long leftAns = solve(num1, min_sum, max_sum);
    bool leftTrue = false; 
    int leftSum = 0; 
    for (auto d: num1){
        leftSum += (d - '0');
    }
    if (leftSum >= min_sum && leftSum <= max_sum){
        leftTrue = true; 
    }
    return (rightAns - leftAns + leftTrue + mod) % mod; 
}
