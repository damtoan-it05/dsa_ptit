#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n;
string s;
char X[maxn];

void Try(int i, int start){
    for(int j = start; j <= n; j++){
        X[i] = s[j];
        if(i >= 1){
            for(int l = 1; l <= i; l++){
                cout << X[l];
            }
            cout << " ";
        }
        Try(i + 1, j + 1);
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n >> s;
        sort(begin(s), end(s));
        s = " " + s;
        Try(1, 1);
        cout << endl;
    }
}