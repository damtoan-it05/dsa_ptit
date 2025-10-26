#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, X[maxn], sum = 0;
vector<string> res;

void Try(int i, int pos){
    for(int j = pos; j >= 1; j--){
        if((sum + j) <= n){
            X[i] = j;
            sum += j;
            if(sum == n){
                string tmp = "(";
                for(int l = 1; l <= i; l++){
                    tmp += to_string(X[l]);
                    if(l != i){
                        tmp += " ";
                    }
                    else{
                        tmp += ")";
                    }
                }
                res.push_back(tmp);
            }
            else{
                Try(i + 1, j);
            }
            sum -= j;
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        sum = 0;
        Try(1, n);
        cout << res.size() << endl;
        for(auto x : res){
            cout << x << " ";
        }
        cout << endl;
        res.clear();
    }
}