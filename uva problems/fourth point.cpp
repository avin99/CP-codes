

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
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double x, y;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        if (x1 == x3 && y1 == y3) {
            x = x2 + x4 - x3;
            y = y2 + y4 - y3;
        } else if (x1 == x4 && y1 == y4) {
            x = x2 + x3 - x4;
            y = y2 + y3 - y4;
        } else if (x2 == x3 && y2 == y3) {
            x = x1 + x4 - x3;
            y = y1 + y4 - y3;
        } else {
            x = x1 + x3 - x4;
            y = y1 + y3 - y4;
        }
        //cout << setprecision(10) << x << " " << setprecision(10) << y << endl;
        printf("%.3f %.3f\n", x, y);
    }
    return 0;
}