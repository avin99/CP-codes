#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll dp[101][101];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    ll n, r, i, j;
    while (cin >> n >> r) {
        if (n == 0 && r == 0)break;
        for (i = 0; i < n + 1; i++) {
            for (j = 0; j < r + 1; j++) {
                if (i == j || j == 0)
                    dp[i][j] = 1;
            }
        }
        for (i = 1; i < n + 1; i++) {
            for (j = 1; j < r + 1; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        cout << n << " things taken " << r << " at a time is " << dp[n][r] << " exactly." << endl;
    }

    return 0;
}