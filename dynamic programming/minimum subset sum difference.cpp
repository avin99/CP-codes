#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool dp[101][1001];
void knapsack(int arr[], int sum, int n) {
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = (( dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]));
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }


}
int subsetdiff(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    knapsack(arr, sum, n);
    vector<int>v;
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i])
            v.PB(i);
    }
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++) {
        mn = min(mn, abs(sum - 2 * v[i]));
    }
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
    cin >> n ;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (subsetdiff(arr, n)) << endl;

    return 0;
}