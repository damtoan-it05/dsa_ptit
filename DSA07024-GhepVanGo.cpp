#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(ll a[], int n){
    ll res = 0;
    stack<int> stk;
    int i = 0;
    while(i < n){
        if((stk.empty()) || (a[i] >= a[stk.top()])){
            stk.push(i);
            ++i;
        }
        else{
            int h = stk.top(); stk.pop();
            if(stk.empty()){
                if(i >= a[h]){
                    res = max(res, a[h] * a[h]);
                }
            }
            else{
                if((i - 1 - stk.top()) >= a[h]){
                    res = max(res, a[h] * a[h]);
                }
            }
        }
    }
    while(!stk.empty()){
        int h = stk.top(); stk.pop();
        if(stk.empty()){
            if(i >= a[h]){
                res = max(res, a[h] * a[h]);
            }
        }
        else{
            if((i - 1 - stk.top()) >= a[h]){
                res = max(res, a[h] * a[h]);
            }
        }      
    }
    cout << sqrt(res) << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        ll a[n];
        for(auto &x : a){
            cin >> x;
        }
        solve(a, n);
    }
}