

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
    double a, b, c, d;
    int i = 0, j;
    double x, y;
    char ch;
    vector<vector<double>>v;
    while (1) {
        cin >> ch;
        if (ch == '*')break;
        cin >> a >> b >> c >> d;
        vector<double> v1;
        v1.PB(a); v1.PB(b); v1.PB(c); v1.PB(d);
        v.PB(v1);
        i++;
    }
    j = 1;

    while (1) {
        int fl = 0;
        cin >> x >> y;
        if (x == 9999.9 && y == 9999.9)break;

        for (i = 0; i < v.size(); i++) {
            if (x > v[i][0] && y < v[i][1] && x < v[i][2] && y > v[i][3] ) {
                cout << "Point " << j << " is contained in figure " << i + 1 << endl; fl = 1;
            }
        }
        if (fl == 0) {
            cout << "Point " << j << " is not contained in any figure" << endl;
        }
        j++;
    }

    return 0;
}