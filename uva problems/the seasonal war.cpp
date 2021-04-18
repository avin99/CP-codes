#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<string>v;
bool visited[30][30];
ll n;
ll dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
ll dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void dfs(ll i, ll j) {
    if (visited[i][j])return;
    visited[i][j] = 1;
    ll k;
    for (k = 0; k < 8; k++) {
        ll ii = i + dx[k];
        ll jj = j + dy[k];
        if (ii < n && ii >= 0 && jj < n && jj >= 0 && !visited[ii][jj] && v[ii][jj] == '1') {
            dfs(ii, jj);
        }
    }

}
int main() {
    IOS;
    ll cnt = 1;
    while (cin >> n) {
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
                if (!visited[i][j] && v[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << "Image number " << cnt++ << " contains " << ans << " war eagles." << endl;
    }
}