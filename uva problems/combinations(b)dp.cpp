#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll dp[101][101];
ll func(ll n, ll r) {
    if (n == r || r == 0)return 1;
    if (dp[n][r] != -1)return dp[n][r];
    dp[n][r] = func(n - 1, r - 1) + func(n - 1, r);
    return dp[n][r];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    ll n, r, i, j;
    memset(dp, -1, sizeof(dp));
    while (cin >> n >> r) {
        if (n == 0 && r == 0)break;


        cout << n << " things taken " << r << " at a time is " << func(n, r) << " exactly." << endl;
    }

    return 0;
}