

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int dp[101][1001];
bool knapsack(int val[], int W, int n) {
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (val[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - val[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][W] == W) {
        return true;
    } else return false;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, i, j, a, b, W;
    cin >> n >> W;
    int val[n];
    for (i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << knapsack(val, W, n) << endl;

    return 0;
}