#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<string>v;
bool visited[100][100];
ll n;
ll dx[8] = {0, 0, 1, -1};
ll dy[8] = {1, -1, 0, 0};
void dfs(ll i, ll j) {
    if (visited[i][j])return;
    visited[i][j] = 1;
    for (ll k = 0; k < 4; k++) {
        ll ix, iy;
        ix = i + dx[k];
        iy = j + dy[k];
        if (ix < n && iy < n && ix >= 0 && iy >= 0 && !visited[ix][iy] && (v[ix][iy] == 'x' || v[ix][iy] == '@')) {
            dfs(ix, iy);
        }
    }
}
int main() {
    IOS;
    ll test = 1, t;
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        ll ans = 0;
        string s;
        memset(visited, 0, sizeof(visited));
        ll i, j;
        for (i = 0; i < n; i++) {
            cin >> s;
            v.PB(s);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (!visited[i][j] && v[i][j] == 'x') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << "Case " << test++ << ": " << ans << endl;
    }
}