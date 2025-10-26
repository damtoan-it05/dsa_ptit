#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int N, P, S, sum = 0, X[maxn];
vector<int> prime;
vector<vector<int>> res;

bool check(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return n > 1;
}

void sieve(){
    for(int i = 2; i <= 200; i++){
        if(check(i)){
            prime.push_back(i);
        }
    }
}

void Try(int i, int pos){
    for(int j = pos; j < prime.size(); j++){
        if((sum + prime[j]) <= S){
            X[i] = prime[j];
            sum += prime[j];
            if((i == N) and (sum == S)){
                vector<int> tmp;
                for(int l = 1; l <= i; l++){
                    tmp.push_back(X[l]);
                }
                res.push_back(tmp);
            }
            else{
                Try(i + 1, j + 1);
            }
            sum -= prime[j];
        }
    }
}

int main(){
    sieve();
    int TC;
    cin >> TC;
    while(TC--){
        cin >> N >> P >> S;
        sum = 0;
        int pos;
        for(int i = 0; i < prime.size(); i++){
            if(prime[i] > P){
                pos = i;
                break;
            }   
        }
        Try(1, pos);
        cout << res.size() << endl;
        for(auto it : res){
            for(auto x : it){
                cout << x << " ";
            }
            cout << endl;
        }
        res.clear();
    }
}