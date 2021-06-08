#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool is_win(string config) {

    bool rows =
        (config[0] != '.' && config[0] == config[1] && config[1] == config[2]) ||
        (config[3] != '.' && config[3] == config[4] && config[4] == config[5]) ||
        (config[6] != '.' && config[6] == config[7] && config[7] == config[8]);

    bool columns =
        (config[0] != '.' && config[0] == config[3] && config[3] == config[6]) ||
        (config[1] != '.' && config[1] == config[4] && config[4] == config[7]) ||
        (config[2] != '.' && config[2] == config[5] && config[5] == config[8]);

    bool diagonals =
        (config[0] != '.' && config[0] == config[4] && config[4] == config[8]) ||
        (config[2] != '.' && config[2] == config[4] && config[4] == config[6]);

    return rows || columns || diagonals;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    ll t = 1;
    cin >> t;
    while (t--) {
        ll i, j, k, m, n;
        string board = "";
        for (i = 0; i < 3; i++) {
            string row;
            cin >> row;
            board += row;
        }
        queue<pair<string, bool>> q;
        string start = ".........";
        string ans = "no";
        q.push(MP(start, 1));
        while (!q.empty()) {
            string cur = q.front().F;
            bool cur_player = q.front().S;
            q.pop();
            if (cur == board) {
                ans = "yes"; break;
            }
            if (is_win(cur))continue;
            for (i = 0; i < 9; i++) {
                if (cur[i] == '.') {
                    cur[i] = (cur_player ? 'X' : 'O');
                    if (cur[i] == board[i])
                        q.push(MP(cur, 1 ^ cur_player));
                    cur[i] = '.';
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}