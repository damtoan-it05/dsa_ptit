#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Tìm kiếm kí tự ở vị trí thứ n trong xâu có độ dài len
char Find(ll len, ll n, string s){
    if(n <= s.size()){
        return s[n-1];
    }
    if(n <= (len / 2)){
        return Find(len / 2, n, s);
    }
    else{
        ll idx = n - (len / 2);
        if(idx == 1){
            return Find(len / 2, len / 2, s);
        }
        else{
            return Find(len / 2, idx - 1, s);
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        ll n, len;
        cin >> s >> n;
        len = s.size();
        while(len < n){
            len *= 2;
        }
        cout << Find(len, n, s) << endl;
    }
}