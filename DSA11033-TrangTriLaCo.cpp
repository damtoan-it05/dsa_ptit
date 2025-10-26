#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    map<int,int> Diff, Prefix;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        ++Diff[x];
        --Diff[y+1];
    }
    int Q; cin >> Q;
    int a[Q];
    for(int i = 0; i < Q; i++){
        cin >> a[i];
        Diff[a[i]] += 0;
    }
    int pos = 0;
    for(auto x : Diff){
        pos += x.second;
        Prefix[x.first] += pos;
    }
    for(int i = 0; i < Q; i++){
        cout << Prefix[a[i]] << endl;
    }
}