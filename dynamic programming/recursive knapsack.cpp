

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int knapsack(int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (wt[n - 1] <= W) {
        return max(val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    } else {
        return knapsack(wt, val, W, n - 1);
    }

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
    int val[n], wt[n];
    for (i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(wt, val, W, n) << endl;

    return 0;
}