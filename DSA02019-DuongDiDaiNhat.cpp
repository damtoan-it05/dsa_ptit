#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, m, X[maxn][maxn], res = 0;

void input(){
    memset(X, 0, sizeof(X));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        X[x][y] = X[y][x] = 1;
    }
}

void DFS(int u, int dis){
    for(int v = 0; v < n; v++){
        if(X[u][v]){
            X[u][v] = X[v][u] = 0;
            res = max(res, dis + 1);
            DFS(v, dis + 1);
            X[u][v] = X[v][u] = 1;

        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        res = 0;
        for(int u = 0; u < n; u++){
            DFS(u, 0);
        }
        cout << res << endl;
    }
}