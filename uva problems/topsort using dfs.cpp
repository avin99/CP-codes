

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

    void topsort(int n, int ordering[]) {
        bool visited[n];
        memset(visited, false, sizeof(visited));
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
    Graph g(6);
    g.addEdge(5, 2, false);
    g.addEdge(5, 0, false);
    g.addEdge(4, 0, false);
    g.addEdge(4, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 1, false);

    cout << "Topological ordering is" << endl;
    g.topsort(6, ordering);

    for (int i = 0; i < 6; i++) {
        cout << ordering[i] << " ";
    }
    return 0;
}