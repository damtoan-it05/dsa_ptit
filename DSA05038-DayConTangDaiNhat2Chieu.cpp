#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100001;

int n;
pair<int,int> a;
set<pair<int,int>> st[maxn];


bool cmp(const pair<int,int> &x, const pair<int,int> &y){
    return x.first < y.first and x.second < y.second;
}

bool check(set<pair<int,int>> &st){
    for(auto x : st){
        if(cmp(x, a)){
            return true;
        }
        else if(x.first >= a.first){
            break;
        }
    }
    return false;
}

int Binary_Search(int L, int R){
    while(L < R){
        int M = (L + R) >> 1;
        if(check(st[M])){
            L = M + 1;
        }
        else{
            R = M;
        }
    }
    return L;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a.first >> a.second;
        int idx = Binary_Search(0, n);
        if(idx < n){
            auto it = ++st[idx].insert(a).first;
            while(it != st[idx].end()){
                if(cmp(a, *it)){
                    st[idx].erase(it++);
                }
                else{
                    it++;
                }
            }
        }
    }
    int res = 0;
    while(res < n and !st[res].empty()){
        ++res;
    }
    cout << res << endl;
}