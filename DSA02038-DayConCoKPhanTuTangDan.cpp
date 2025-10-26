#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, k, a[maxn], X[maxn];

void input(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void Try(int i, int pos){
    for(int j = pos; j <= n; j++){
        X[i] = a[j];
        if(i == k){
            for(int l = 1; l <= k; l++){
                cout << X[l] << " ";
            }
            cout << endl;
        }
        else{
            Try(i + 1, j + 1);
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Try(1, 1);
    }
}