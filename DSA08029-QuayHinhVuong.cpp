#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void Change1(vector<int> &vt){
    vector<int> tmp = vt;
    vt[0] = tmp[3];
    vt[1] = tmp[0];
    vt[4] = tmp[1];
    vt[3] = tmp[4];
}

void Change2(vector<int> &vt){
    vector<int> tmp = vt;
    vt[1] = tmp[4];
    vt[2] = tmp[1];
    vt[5] = tmp[2];
    vt[4] = tmp[5];
}

void solve(vector<int> X, vector<int> Y){
    map<vector<int>, int> mp;
    queue<pair<vector<int>, int>> Q;
    Q.push({X, 0});
    mp[X] = 1;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        if(it.first == Y){
            cout << it.second << endl;
            return;
        }
        vector<int> tmp1 = it.first;
        Change1(tmp1);
        if(tmp1 == Y){
            cout << it.second + 1 << endl;
            return;
        }
        else{
            if(!mp[tmp1]){
                Q.push({tmp1, it.second + 1});
            }
        }
        vector<int> tmp2 = it.first;
        Change2(tmp2);
        if(tmp2 == Y){
            cout << it.second + 1 << endl;
            return;
        }
        else{
            if(!mp[tmp2]){
                Q.push({tmp2, it.second + 1});
            }
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        vector<int> X, Y;
        for(int i = 0; i < 6; i++){
            int it; cin >> it;
            X.push_back(it);
        }
        for(int i = 0; i < 6; i++){
            int it; cin >> it;
            Y.push_back(it);
        }
        solve(X, Y);     
    }
}