

#include<bits/stdc++.h>
#define ll long long int
#define PB emplace_back
#define MP make_pair
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int ordering[6] = {0};
using namespace std;
class Graph {
    int V;
public:

    list<int>*adjList;
    Graph(int v) {
        V = v;
        adjList = new list<int>[V];
    }
    void addEdge(int u, int v, bool bidir = true) {
        adjList[u].PB(v);
        if (bidir) {
            adjList[v].PB(u);
        }
    }

    void topsort(int n) {
        bool visited[n];

        memset(visited, false, sizeof(visited));
        memset(ordering, 0, sizeof(ordering));
        int i = n - 1;
        for (int at = 0; at < n; at++) {
            if (visited[at] == false) {
                i = dfs(i, at, visited, ordering);
            }
        }

    }
    int dfs(int i, int at, bool visited[], int ordering[]) {
        visited[at] = true;
        for (auto edge : adjList[at]) {
            if (visited[edge] == false) {
                i = dfs(i, edge, visited, ordering);
            }
        }
        ordering[i] = at;
        return i - 1;
    }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    IOS;
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0)return 0;
        Graph g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g.addEdge(x - 1, y - 1, false);
        }

        g.topsort(n);

        for (int i = 0; i < n; i++) {
            cout << ordering[i] + 1 << " ";
        }
        cout << endl;

    }
    return 0;
}