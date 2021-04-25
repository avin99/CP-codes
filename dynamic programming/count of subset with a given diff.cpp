#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int dp[101][1001];
int knapsack(int arr[], int diff, int n) {
    int sum, total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    if ((diff + total) % 2 != 0)return 0;
    sum = (diff + total) / 2;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = (( dp[i - 1][j - arr[i - 1]]) + (dp[i - 1][j]));
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, i, j, a, b, diff;
    cin >> n >> diff;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << knapsack(arr, diff, n) << endl;


    return 0;
}