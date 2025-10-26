#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100001;

bool prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return n > 1;
}

void solve(int s, int t){
    int visited[maxn] = {0};
    queue<pair<int,int>> Q;
    Q.push({s, 0});
    visited[s] = 1;
    while(!Q.empty()){
        auto tmp = Q.front(); Q.pop();
        if(tmp.first == t){
            cout << tmp.second << endl;
            return;
        }
        string s = to_string(tmp.first);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            for(char j = '0'; j <= '9'; j++){
                if((i == 0) and (j == '0')){
                    continue;
                }
                if(c != j){
                    s[i] = j;
                    int x = stoi(s);
                    if(x == t){
                        cout << tmp.second + 1 << endl;
                        return;
                    }
                    if((prime(x)) and (!visited[x])){
                        Q.push({x, tmp.second + 1});
                        visited[x] = 1;
                    }
                }
            }
            s[i] = c;
        }
    }

}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int s, t;
        cin >> s >> t;
        solve(s, t);
    }
}