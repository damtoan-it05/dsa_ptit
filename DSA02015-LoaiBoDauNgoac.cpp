#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool check(string s){
    if(s.size() == 0 || s.size() == 1){
        return false;
    }
    stack<char> stk;
    for(auto x : s){
        if(isalpha(x)){
            continue;
        }
        if(stk.empty() || x == '('){
            stk.push(x);
        }
        else if(x == ')'){
            if(stk.empty()){
                return false;
            }
            else{
                if(stk.top() == '('){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(!stk.empty()) return false;
    return true;
}

set<string> BFS(string s){
    set<string> res;
    queue<string> Q;
    map<string,int> mask;
    Q.push(s);
    mask[s] = 1;
    bool flag = false;
    while(!Q.empty()){
        auto it = Q.front(); Q.pop();
        if(check(it)){
            res.insert(it);
            flag = true;
        }
        if(flag){
            continue;
        }
        for(int i = 0; i < it.size(); i++){
            if(it[i] == '(' || it[i] == ')'){
                string tmp = it;
                tmp = tmp.erase(i, 1);
                if(!mask[tmp]){
                    mask[tmp] = 1;
                    Q.push(tmp);
                }
            }
        }
    }
    return res;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        set<string> ans = BFS(s);
        if(ans.size()){
            for(auto x : ans){
                cout << x << " ";
            }
            cout << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
}