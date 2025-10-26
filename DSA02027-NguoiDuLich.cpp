#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, c_min = INT_MAX, F = 0, Fopt = INT_MAX;
int a[maxn][maxn], X[maxn] = {0, 1}, mark[maxn] = {0};

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(i != j){
                c_min = min(c_min, a[i][j]);
            }
        }
    }
}

void Try(int i){
    for(int j = 2; j <= n; j++){
        if(mark[j] == 0){
            X[i] = j;
            mark[j] = 1;
            F += a[X[i-1]][X[i]];
            if(i == n){
                Fopt = min(Fopt, F + a[X[i]][1]);
            }
            else if((F + c_min * (n - i + 1)) < Fopt){
                Try(i + 1);
            }
            mark[j] = 0;
            F -= a[X[i-1]][X[i]];
        }
    }
}

int main(){
    input();
    Try(2);
    cout << Fopt << endl;
}