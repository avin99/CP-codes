#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<string>v;
ll n, m, p = 1;
ll dx[3] = {0, -1, 0};
ll dy[3] = { -1, 0, 1};
string ans[3] = {"left", "forth", "right"};
string str = "@IEHOVA#";

void dfs(ll i, ll j) {
    if (p == 8)return;
    for (ll k = 0; k < 3; k++) {
        ll ii = i + dx[k];
        ll jj = j + dy[k];
        if (ii < m && ii >= 0 && jj < n && jj >= 0 && v[ii][jj] == str[p]) {
            p++;
            if (p == 8)
                cout << ans[k];
            else
                cout << ans[k] << " ";
            dfs(ii, jj);
        }
    }

}
int main() {
    IOS;
    ll t;
    cin >> t;
    while (t--) {
        p = 1;
        v.clear();
        cin >> m >> n;
        ll x, y;
        string s;
        ll i, j, fl = 0;
        for (i = 0; i < m; i++) {
            cin >> s;
            v.PB(s);
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (v[i][j] == '@') {
                    x = i; y = j; fl = 1; break;
                }
            }
            if (fl == 1)break;
        }
        dfs(x, y);
        cout << endl;
    }
}