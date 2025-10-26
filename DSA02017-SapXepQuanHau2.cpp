#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int a[maxn][maxn], X[maxn], cot[maxn], cheo1[maxn], cheo2[maxn], res;

void input(){
    res = 0;
    memset(cot, 0, sizeof(cot));
    memset(cheo1, 0, sizeof(cheo1));
    memset(cheo2, 0, sizeof(cheo2));
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> a[i][j];
        }
    }
}

void Try(int i){
    for(int j = 1; j <= 8; j++){
        if((cot[j] == 0) and (cheo1[i+j-1] == 0) and (cheo2[i-j+8] == 0)){
            cot[j] = 1; cheo1[i+j-1] = 1; cheo2[i-j+8] = 1;
            X[i] = j;
            if(i == 8){
                int sum = 0;
                for(int l = 1; l <= 8; l++){
                    sum += a[l][X[l]];
                }
                res = max(res, sum);
            }
            else{
                Try(i + 1);
            }
            cot[j] = 0; cheo1[i+j-1] = 0; cheo2[i-j+8] = 0;
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Try(1);
        cout << res << endl;
    }
}