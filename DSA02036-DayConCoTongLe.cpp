#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, a[maxn], X[maxn], sum = 0;
vector<vector<int>> res;

void input(){
    sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
}

void Try(int i, int pos){
    for(int j = pos; j <= n; j++){
        X[i] = a[j];
        sum += a[j];
        if(sum % 2 != 0){
            vector<int> tmp;
            for(int l = 1; l <= i; l++){
                tmp.push_back(X[l]);
            }
            res.push_back(tmp);
        }
        Try(i + 1, j + 1);
        sum -= a[j];
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Try(1, 1);
        sort(begin(res), end(res));
        for(auto it : res){
            for(auto x : it){
                cout << x << " ";
            }
            cout << endl;
        }
        res.clear();
    }
}