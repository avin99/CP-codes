int dp[503][503];
bool ispalindrome(string s, int i, int j) {
    if (i == j)return true;
    if (i > j)return false;
    while (i < j) {
        if (s[i] != s[j])return false;
        i++; j--;
    }
    return true;
}
int solve(string s, int i, int j) {
    if (i >= j)return 0;
    if (ispalindrome(s, i, j))return 0;
    if (dp[i][j] != -1)return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int left, right;
        if (dp[i][k] != -1) left = dp[i][k];
        else {
            left = solve(s, i, k);
            dp[i][k] = left;
        }
        if (dp[k + 1][j] != -1) right = dp[k + 1][j];
        else {
            right = solve(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = 1 + left + right;
        if (temp < mn) {
            mn = temp;
        }
    }
    dp[i][j] = mn;
    return mn;

}