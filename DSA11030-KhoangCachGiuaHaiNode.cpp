#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 1001;

int n, q, parent[maxn], depth[maxn], visited[maxn];
vector<int> Ke[maxn];

void init(){
    memset(visited, 0, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    memset(Ke, 0, sizeof(Ke));
}

void DFS(int u, int d){
    visited[u] = 1;
    depth[u] = d;
    for(int v : Ke[u]){
        if(!visited[v]){
            parent[v] = u;
            DFS(v, d + 1);
        }
    }
}

int LCA(int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    while(depth[u] > depth[v]){
        u = parent[u];
    }
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main(){
    int TC; cin >> TC;
    while(TC--){
        init();
        cin >> n;
        for(int i = 1; i < n; i++){
            int x, y;
            cin >> x >> y;
            Ke[x].push_back(y);
            Ke[y].push_back(x);
        }
        DFS(1, 0);
        cin >> q;
        while(q--){
            int u, v;
            cin >> u >> v;
            int dist = depth[u] + depth[v] - 2 * depth[LCA(u, v)];
            cout << dist << endl;
        }
    }
}