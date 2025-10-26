#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100005;

int n, visited[maxn];
vector<int> Ke[maxn];

void input(){
    memset(Ke, 0, sizeof(Ke));
    memset(visited, 0, sizeof(visited));
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
}

void BFS(int u){
    int d[maxn] = {0};
    queue<int> Q;
    Q.push(u);
    visited[u] = 1;
    while(!Q.empty()){
        int it = Q.front(); Q.pop();
        for(int v : Ke[it]){
            if(!visited[v]){
                Q.push(v);
                visited[v] = 1;
                d[v] = d[it] + 1;
            }
        }
    }
    cout << *max_element(d + 1, d + n + 1) << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        BFS(1);
    }
}