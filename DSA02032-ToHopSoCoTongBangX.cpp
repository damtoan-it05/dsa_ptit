#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, S, X[maxn], a[maxn], sum = 0;
vector<string> res;

void input(){
    sum = 0;
    cin >> n >> S;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void Try(int i, int pos){
    for(int j = pos; j <= n; j++){
        if((sum + a[j]) <= S){
            X[i] = a[j];
            sum += a[j];
            if(sum == S){
                string tmp = "{";
                for(int l = 1; l <= i; l++){
                    tmp += to_string(X[l]);
                    if(l != i){
                        tmp += " ";
                    }
                    else{
                        tmp += "}";
                    }
                }
                res.push_back(tmp);
            }
            else{
                Try(i + 1, j);
            }
            sum -= a[j];
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Try(1, 1);
        if(res.size() == 0){
            cout << "-1" << endl;
        }
        else{
            cout << res.size() << " ";
            for(auto x : res){
                cout << x << " ";
            }
            cout << endl;
        }
        res.clear();
    }
}