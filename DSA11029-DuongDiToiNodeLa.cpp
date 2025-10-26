#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 1001;

int n;
vector<int> Ke[maxn];

void input(){
    memset(Ke, 0, sizeof(Ke));
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        Ke[x].push_back(y);
        Ke[y].push_back(x);
    }
}

void BFS(int u){
    int mark[maxn] = {0}, visited[maxn] = {0}, parent[maxn] = {0};
    queue<int> Q; 
    Q.push(u); 
    visited[u] = 1;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        bool check = true;
        for(int v : Ke[it]){
            if(!visited[v]){
                check = false;
                visited[v] = 1;
                Q.push(v);
                parent[v] = it;
            }
        }
        if(check){
            mark[it] = 1;
        }
    }
    for(int i = 2; i <= n; i++){
        if(mark[i]){
            vector<int> path;
            int u = i;
            while(u != 1){
                path.push_back(u);
                u = parent[u];
            }
            path.push_back(1);
            reverse(begin(path), end(path));
            for(auto x : path){
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        BFS(1);
    }
}