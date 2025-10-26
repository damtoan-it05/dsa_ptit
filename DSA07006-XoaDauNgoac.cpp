#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 100;
string s;
map<int, pair<int,int>> mp;
int cnt = 1;
void Mark(){
    stack<int> stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            stk.push(i);
        }
        else if(s[i] == ')'){
            mp[cnt++] = {stk.top(), i};
            stk.pop();
        }
    }
}

int X[maxn];
set<string> ans;

void Try(int i){
    for(int j = 0; j <= 1; j++){
        X[i] = j;
        if(i == (cnt - 1)){
            string tmp = s;
            for(int l = 1; l <= i; l++){
                if(X[l]){
                    tmp[mp[l].first] = '@';
                    tmp[mp[l].second] = '@';
                }
            }
            string x = "";
            for(auto it : tmp){
                if(it != '@'){
                    x += it;
                }
            }
            if(x != s){
                ans.insert(x);
            }
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    cin >> s;
    Mark();
    Try(1);
    for(auto it : ans){
        cout << it << endl;
    }
}