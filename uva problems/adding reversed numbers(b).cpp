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
    string a, b, res, a1, b1;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        i = 0;
        while (a[i] == '0' && i < a.size()) {
            i++;
        }
        j = 0;
        while (b[j] == '0' && j < b.size()) {
            j++;
        }
        a1 = a.substr(i, a.size() - i);
        b1 = b.substr(j, b.size() - j);

        reverse(a1.begin(), a1.end());
        reverse(b1.begin(), b1.end());
        if (a1.size() > b1.size())
            swap(a1, b1);

        ll k;
        ll sum, carry = 0;
        for (k = 0; k < a1.size(); k++) {

            sum = (a1[k] - '0') + (b1[k] - '0') + carry;
            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        for (k = a1.size(); k < b1.size(); k++) {
            sum = (b1[k] - '0') + carry;
            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) {
            res += (carry + '0');
        }
        string ans;
        i = 0;
        while (res[i] == '0' && i < res.size()) {
            i++;
        }
        ans = res.substr(i, res.size() - i);
        cout << ans << endl;

    }

    return 0;
}