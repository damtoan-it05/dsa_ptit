#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int k, m, n, visited[maxn][maxn];
char a[maxn][maxn];
set<string> dic;
vector<string> res;

void input(){
    memset(visited, 0, sizeof(visited));
    dic.clear();
    res.clear();
    cin >> k >> m >> n;
    for(int i = 0; i < k; i++){
        string s;
        cin >> s;
        dic.insert(s);
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string str = "";

void Try(int i, int j){
    if(dic.find(str) != dic.end()){
        res.push_back(str);
    }
    for(int k = 0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if((i1 >= 1) and (i1 <= m) and (j1 >= 1) and (j1 <= n) and (!visited[i1][j1])){
            visited[i1][j1] = 1;
            str += a[i1][j1];
            Try(i1, j1);
            visited[i1][j1] = 0;
            str.pop_back();
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                str = a[i][j];
                memset(visited, 0, sizeof(visited));
                visited[i][j] = 1;
                Try(i, j);
            }
        }
        if(res.size() == 0){
            cout << "-1" << endl;
        }
        else{
            for(auto it : res){
                cout << it << " ";
            }
            cout << endl;
        }
    }
}