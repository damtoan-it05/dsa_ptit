#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;
const ll MOD = 1e15 + 7;

ll Tich(ll a, ll b){
    if(b == 0){
        return 0;
    }
    ll x = Tich(a, b/2) % MOD;
    if(b % 2 == 0){
        return ((x + x) % MOD);
    }
    else{
        return (((a % MOD) + ((x + x) % MOD)) % MOD);
    }
}

struct Matrix{
    ll X[maxn][maxn];
    Matrix(){
        memset(X, 0, sizeof(X));
    }
    friend Matrix operator * (Matrix a, Matrix b){
        Matrix res;
        for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 3; j++){
                ll tmp = 0;
                for(int k = 0; k <= 3; k++){
                    tmp += Tich(a.X[i][k], b.X[k][j]);
                    tmp %= MOD;
                }
                res.X[i][j] = tmp;
            }
        }
        return res;
    }
};

Matrix Luy_Thua(Matrix a, ll n){
    Matrix res;
    res.X[0][0] = res.X[1][1] = res.X[2][2] = res.X[3][3] = 1;
    while(n){
        if(n & 1){
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;
}

// {1, 1, 1, 0}
// {1, 0, 0, 0}
// {0, 1, 0, 0}
// {1, 1, 1, 1}

void Solve(ll n){
    Matrix a;
    a.X[0][0] = a.X[0][1] = a.X[0][2] = a.X[1][0] = a.X[2][1] = 1;
    a.X[3][0] = a.X[3][1] = a.X[3][2] = a.X[3][3] = 1;
    a = Luy_Thua(a, n);
    cout << a.X[3][1] << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        ll n;
        cin >> n;
        Solve(n);
    }
}