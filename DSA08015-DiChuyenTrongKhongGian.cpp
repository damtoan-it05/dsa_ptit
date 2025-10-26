#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 50;
struct Node{
    int x, y, z;
};

int A, B, C;
char X[maxn][maxn][maxn];
Node start, target;

void input(){
    cin >> A >> B >> C;
    for(int k = 1; k <= A; k++){
        for(int i = 1; i <= B; i++){
            for(int j = 1; j <= C; j++){
                cin >> X[i][j][k];
                if(X[i][j][k] == 'S'){
                    start = {i, j, k};
                }
                else if(X[i][j][k] == 'E'){
                    target = {i, j, k};
                }
            }
        }
    }
}

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

void solve(){
    int visited[maxn][maxn][maxn] = {0};
    queue<pair<Node,int>> Q;
    Q.push({start, 0});
    visited[start.x][start.y][start.z] = 1;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        int i = it.first.x; 
        int j = it.first.y; 
        int k = it.first.z;
        if((i == target.x) && (j == target.y) && (k == target.z)){
            cout << it.second << endl;
            return;
        }
        for(int l = 0; l < 6; l++){
            int i1 = i + dx[l];
            int j1 = j + dy[l];
            int k1 = k + dz[l];
            if((i1 == target.x) && (j1 == target.y) && (k1 == target.z)){
                cout << it.second + 1 << endl;
                return;
            }
            if((i1 >= 1) and (i1 <= B) and (j1 >= 1) and (j1 <= C) and (k1 >= 1) and (k1 <= A) and (X[i1][j1][k1] != '#')){
                if(!visited[i1][j1][k1]){
                    visited[i1][j1][k1] = 1;
                    Q.push({{i1, j1, k1}, it.second + 1});
                }
            }
        }
    }
    cout << "-1" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        input();
        solve();
    }
}