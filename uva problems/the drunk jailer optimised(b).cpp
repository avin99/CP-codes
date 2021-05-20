#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    ll n, m, i, j, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll a[n + 1] = {0};

        for (i = 2; i <= n; i++) {
            ll x = sqrt(i);
            if (x * x == i) {
                a[i] = 0;
            } else {
                a[i] = 1;
            }
        }
        ll cnt = 1;
        for (i = 2; i <= n; i++) {
            if (a[i] == 0)cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}