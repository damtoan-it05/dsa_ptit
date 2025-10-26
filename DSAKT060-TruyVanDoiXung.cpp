#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool check(string s){
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return s == tmp;
}

int main(){
    string s;
    cin >> s;
    s = " " + s;
    int Q;
    cin >> Q;
    while(Q--){
        int L, R; char c;
        cin >> c >> L >> R;
        if(c == 'c'){
            s[L] = R + '0';
        }
        else{
            string tmp = s.substr(L, R - L + 1);
            if(check(tmp)){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}