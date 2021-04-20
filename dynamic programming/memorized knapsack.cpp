

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int dp[101][1001];
int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (dp[n][W] != -1)
        return dp[n][W];
    if (wt[n - 1] <= W) {
        dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
        return dp[n][W];
    } else {
        dp[n][W] = knapsack(wt, val, W, n - 1);
        return dp[n][W];
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    memset(dp, -1, sizeof(dp));
    int n, i, j, a, b, W;
    cin >> n >> W;
    int val[n], wt[n];
    for (i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(wt, val, W, n) << endl;

    return 0;
}