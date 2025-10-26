#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 100;

struct Matrix{
    ll x[maxn][maxn];
    Matrix(){
        memset(x, 0, sizeof(x));
    }
    friend Matrix operator * (Matrix a, Matrix b){
        Matrix res;
        for(int i = 1; i <= 2; i++){
            for(int j = 1; j <= 2; j++){
                ll tmp = 0;
                for(int k = 1; k <= 2; k++){
                    tmp += (a.x[i][k] * b.x[k][j]);
                    tmp %= MOD;
                }
                res.x[i][j] = tmp;
            }
        }
        return res;
    }
};

Matrix Luy_Thua(Matrix a, ll n){
    Matrix res;
    res.x[1][1] = res.x[2][2] = 1;
    while(n){
        if((n % 2) == 1){
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        ll n;
        cin >> n;
        Matrix tmp;
        tmp.x[1][1] = tmp.x[1][2] = tmp.x[2][1] = 1;
        Matrix ans = Luy_Thua(tmp, n);
        cout << ans.x[1][2] << endl;
    }
}