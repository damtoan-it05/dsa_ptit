#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int n;
string S, T;
set<string> st;

void input(){
    st.clear();
    cin >> n >> S >> T;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        st.insert(x);
    }
}

void solve(){
    unordered_map<string, int> mp;
    queue<pair<string,int>> Q;
    Q.push({S, 1});
    mp[S] = 1;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        if(it.first == T){
            cout << it.second << endl;
            return;
        }
        string str = it.first;
        for(int i = 0; i < str.size(); i++){
            char c = str[i];
            for(char j = 'A'; j <= 'Z'; j++){
                if(c != j){
                    str[i] = j;
                    if(str == T){
                        cout << it.second + 1 << endl;
                        return;
                    }
                    if((st.count(str) != 0) and (!mp[str])){
                        Q.push({str, it.second + 1});
                        mp[str] = 1;
                    }
                }
            }  
            str[i] = c; 
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        solve();
    }
}