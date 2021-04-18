

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {

    IOS;
    ll n, m, i, j, x, ans1 = INT_MIN, ans2 = INT_MAX, l, r, mid;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)cin >> a[i];
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> x;
        ans1 = INT_MIN; ans2 = INT_MAX;
        l = 0; r = n - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (a[mid] < x) {
                l = mid + 1;
                if (ans1 < a[mid])
                    ans1 = a[mid];
            } else  {
                r = mid - 1;
            }
        }
        l = 0; r = n - 1;
        // cout<<l<<" "<<r<<endl;
        while (l <= r) {
            mid = l + (r - l) / 2;
            //cout<<l<<" "<<r<<endl;
            if (a[mid] > x) {
                r = mid - 1;
                if (ans2 > a[mid])
                    ans2 = a[mid];
            } else  {
                l = mid + 1;
            }
        }
        //  cout<<"he"<<endl;
        if (a[0] >= x) {
            cout << "X ";
        } else {
            cout << ans1 << " ";
        }
        if (a[n - 1] <= x) {
            cout << "X" << endl;
        } else {
            cout << ans2 << endl;
        }
    }
    return 0;
}