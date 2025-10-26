#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> res;

void solve(){
    queue<int> Q;
    for(int i = 1; i <= 5; i++){
        Q.push(i);
    }
    while(Q.front() <= 100000){
        int x = Q.front(); Q.pop();
        res.push_back(x);
        int mark[10] = {0};
        int tmp = x;
        while(tmp){
            mark[tmp % 10] = 1;
            tmp /= 10;
        }
        for(int i = 0; i <= 5; i++){
            if(!mark[i]){
                Q.push(10*x + i);
            }
        }
    }
}

int main(){
    solve();
    int TC;
    cin >> TC;
    while(TC--){
        int L, R;
        cin >> L >> R;
        int cnt = 0;
        for(auto x : res){
            if(x > R){
                break;
            }
            if((x >= L) and (x <= R)){
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
}