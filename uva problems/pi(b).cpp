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
    ll n, r, i, j;
    while (cin >> n) {
        if (n == 0)break;
        ll a[n];
        for (i = 0; i < n; i++)cin >> a[i];
        ll cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (__gcd(a[i], a[j]) == 1)cnt++;
            }
        }
        ll ch = n * (n - 1) / 2;
        if (cnt > 0) {
            cout << fixed << setprecision(6) << sqrt((6.0 * ch) / cnt) << endl;

        } else {
            cout << "No estimate for this data set." << endl;
        }
    }

    return 0;
}