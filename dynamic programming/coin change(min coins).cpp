#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int knapsack(int wt[], int sum, int n) {
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0 && i != 0)
                dp[i][j] = 0;
            if (i == 1 && j >= 1) {
                if (j % wt[0] == 0) {
                    dp[i][j] = j / wt[0];
                } else {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
    }
    for (int i = 2; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - wt[i - 1]] , dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][sum] > 1000000)return -1;
    return dp[n][sum];

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, i, j, a, b, sum;
    cin >> sum >> n;
    int wt[n];
    for (i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << knapsack(wt, sum, n) << endl;

    return 0;
}