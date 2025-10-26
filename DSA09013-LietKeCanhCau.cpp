#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[1005];
int in[1005], low[1005], visited[1005];
int v, e, timer;
vector<pair<int,int>> vt;
void dfs(int u, int parent) {
    visited[u] = 1;
    in[u] = low[u] = ++timer;

    for (int x : adj[u]) {
        if (x == parent) continue;
        if (visited[x]) {
            low[u] = min(low[u], in[x]);
        } else {
            dfs(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] > in[u]) {
                vt.push_back({min(u,x), max(u,x)});
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vt.clear();
        cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            adj[i].clear();
            visited[i] = in[i] = low[i] = 0;
        }
        timer = 0;
        for (int i = 1; i <= e; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) dfs(i, -1);
        }
        // sap xep lai và in kq
        sort(vt.begin(),vt.end());
        for (auto c:vt) {
            cout << c.first << " " << c.second << " ";
        }
        cout << endl;
    }
    return 0;
}