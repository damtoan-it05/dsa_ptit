#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        unordered_map<int,int> mp;
        for(auto &x : a){
            cin >> x;
            ++mp[x];
        }
        int res[n];
        stack<int> stk;
        for(int i = 0; i < n; i++){
            if(stk.empty()){
                stk.push(i);
            }
            else{
                while((!stk.empty()) and (mp[a[i]] > mp[a[stk.top()]])){
                    res[stk.top()] = a[i];
                    stk.pop();
                }
                stk.push(i);
            }
        }
        while(!stk.empty()){
            res[stk.top()] = -1;
            stk.pop();
        }
        for(int i = 0; i < n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}