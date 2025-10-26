#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin >> n;
    string a[n+1];
    int X[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        X[i] = i;
    }
    int pos[100][100]; // pos[i][j] = pos[j][i]: Lưu số lượng kí tự lặp lại của xâu ở vị trí i và j
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int cnt = 0;
            for(int l = 0; l < a[j].size(); l++){
                if(a[i].find(a[j][l]) != string::npos){
                    ++cnt;
                }
            }
            pos[i][j] = pos[j][i] = cnt;
        }
    }
    int res = INT_MAX;
    do{
        int count = 0;
        for(int i = 2; i <= n; i++){
            count += pos[X[i]][X[i-1]];
        }
        res = min(res, count);
    } while(next_permutation(X + 1, X + n + 1));
    cout << res << endl;
}