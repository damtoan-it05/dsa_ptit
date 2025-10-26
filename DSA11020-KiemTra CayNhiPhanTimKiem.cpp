#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool check(vector<int> vt, set<int> st){
    if(vt.size() != st.size()){
        return false;
    }
    int idx = 0;
    for(auto x : st){
        if(x != vt[idx++]){
            return false;
        }
    }
    return true;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> vt;
        set<int> st;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            vt.push_back(x);
            st.insert(x);
        }
        if(check(vt, st)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}