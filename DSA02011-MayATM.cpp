#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, S, a[maxn], sum, res;
bool check;

void input(){
    check = true;
    sum = 0;
    res = INT_MAX;
    cin >> n >> S;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
}

void Try(int i, int pos){
    for(int j = pos; j <= n; j++){
        if((sum + a[j]) <= S){
            sum += a[j];
            if(sum == S){
                check = false;
                res = min(res, i);
            }
            else{
                Try(i + 1, j + 1);
            }
            sum -= a[j];
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Try(1, 1);
        if(check){
            cout << "-1" << endl;
        }
        else{
            cout << res << endl;
        }
    }
}