

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool knapsack(int val[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += val[i];
    }
    if (sum % 2 != 0)return false;
    int W = sum / 2;
    bool dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (val[i - 1] <= j) {
                dp[i][j] = ((dp[i - 1][j - val[i - 1]]) || (dp[i - 1][j]));
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, i, j, a, b, sum;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (knapsack(arr, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}