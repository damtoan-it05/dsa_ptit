#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 1005;

ll P[maxn][maxn];

void init(){
    for(int n = 1; n <= 1000; n++){
        for(int k = 1; k <= n; k++){
            if(k == 1){
                P[n][k] = n;
            }
            else{
                P[n][k] = k * P[n-1][k-1] + P[n-1][k];
                P[n][k] %= MOD;
            }
        }
    }
}

int main(){
    init();
    int TC;
    cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        cout << P[n][k] << endl;
    }
}