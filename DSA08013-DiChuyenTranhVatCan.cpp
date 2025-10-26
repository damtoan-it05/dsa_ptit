#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 105;

struct Node{
    int x, y;
};

int n, a, b, c, d;
char X[maxn][maxn];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> X[i][j];
        }
    }
    cin >> a >> b >> c >> d;
}

void solve(){
    int visited[maxn][maxn] = {0};
    queue<pair<Node, int>> Q;
    Q.push({{a, b}, 0});
    visited[a][b] = 1;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        int i = it.first.x;
        int j = it.first.y;
        if((i == c) and (j == d)){
            cout << it.second << endl;
            return;
        }
        for(int k = i - 1; k >= 0; k--){
            if(X[k][j] == 'X'){
                break;
            }
            if((k == c) and (j == d)){
                cout << it.second + 1 << endl;
                return;
            }
            if(!visited[k][j]){
                Q.push({{k, j}, it.second + 1});
                visited[k][j] = 1;
            }
        }
        for(int k = i + 1; k < n; k++){
            if(X[k][j] == 'X'){
                break;
            }
            if((k == c) and (j == d)){
                cout << it.second + 1 << endl;
                return;
            }
            if(!visited[k][j]){
                Q.push({{k, j}, it.second + 1});
                visited[k][j] = 1;
            }
        }    
        for(int h = j - 1; h >= 0; h--){
            if(X[i][h] == 'X'){
                break;
            }
            if((i == c) and (h == d)){
                cout << it.second + 1 << endl;
                return;
            }
            if(!visited[i][h]){
                Q.push({{i, h}, it.second + 1});
                visited[i][h] = 1;
            }
        }    
        for(int h = j + 1; h < n; h++){
            if(X[i][h] == 'X'){
                break;
            }
            if((i == c) and (h == d)){
                cout << it.second + 1 << endl;
                return;
            }
            if(!visited[i][h]){
                Q.push({{i, h}, it.second + 1});
                visited[i][h] = 1;
            }
        }         
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        solve();
    }
}