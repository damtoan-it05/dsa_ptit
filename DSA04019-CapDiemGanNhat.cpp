#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(pair<int,int> a[], int n){
    double dis = 1.0 * 1e9;
    set<pair<int,int>> st; // {y, x}
    int idx = 0;
    for(int i = 0; i < n; i++){
        while((a[i].first - a[idx].first) >= dis){
            st.erase({a[idx].second, a[idx].first});
            ++idx;
        }
        auto x = st.lower_bound({a[i].second - dis, a[i].first});
        auto y = st.upper_bound({a[i].second + dis, a[i].first});
        for(auto it = x; it != y; it++){
            double tmp = sqrt((a[i].first - it->second) * (a[i].first - it->second) + (a[i].second - it->first) * (a[i].second - it->first));
            dis = min(dis, tmp);
        }
        st.insert({a[i].second, a[i].first});
    }
    cout << fixed << setprecision(6) << dis << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        pair<int,int> a[n]; // {x, y}
        for(auto &x : a){
            cin >> x.first >> x.second;
        }
        sort(a, a + n);
        solve(a, n);
    }
}