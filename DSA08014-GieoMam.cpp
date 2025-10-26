#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 505;

int n, m, a[maxn][maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

bool check(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        int day = 0;
        bool mark[maxn][maxn] = {0};
        while(1){
            int visited[maxn][maxn] = {0};
            bool ok = true;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if((a[i][j] == 2) and (!visited[i][j]) and (!mark[i][j])){
                        mark[i][j] = 1;
                        for(int k = 0; k < 4; k++){
                            int i1 = i + dx[k];
                            int j1 = j + dy[k];
                            if((i1 >= 1) and (i1 <= n) and (j1 >= 1) and (j1 <= m) and (a[i1][j1] == 1)){
                                a[i1][j1] = 2;
                                visited[i1][j1] = 1;
                                ok = false;
                            }
                        }
                    }
                }
            }
            if(ok){
                break;
            }
            else{
                ++day;
            }
        }
        if(check()){
            cout << day << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
}