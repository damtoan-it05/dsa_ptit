#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int k;
        string s;
        cin >> k >> s;
        map<int,int> mp;
        for(auto &x : s){
            ++mp[x];
        }
        priority_queue<int> pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k--){
            int x = pq.top();
            pq.pop();
            --x;
            if(x > 0){
                pq.push(x);
            }
        }
        ll res = 0;
        while(!pq.empty()){
            res += (ll)(pq.top() * pq.top());
            pq.pop();
        }
        cout << res << endl;
    }
}