#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dp[102][102];
int solve(int arr[], int i, int j) {

    if (i >= j)return 0;
    if (dp[i][j] != -1)return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempans < mn) {
            mn = tempans;
        }
    }
    dp[i][j] = mn;
    return mn;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, i, j, a, b, sum;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, 1, n - 1) << endl;

    return 0;
}