int longestCommonSubstr (string s1, string s2, int x, int y)
{
    // your code here
    int i, j, mx = INT_MIN;
    int dp[x + 1][y + 1];
    for (i = 0; i <= x; i++) {
        for (j = 0; j <= y; j++) {
            if (i == 0 || j == 0)dp[i][j] = 0;
        }
    }
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else
                dp[i][j] = 0;

        }
    }
    for (i = 0; i <= x; i++) {
        for (j = 0; j <= y; j++) {
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}