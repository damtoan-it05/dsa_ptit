#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, k, a[maxn], sum = 0, res = 0;

void Try(int i, int val, int cnt){
    if((i == (n + 1)) and (cnt == k)){
        ++res;
        return;
    }
    for(int j = i; j <= n; j++){
        val += a[j];
        if(val == sum){
            Try(j + 1, 0, cnt + 1);
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % k){
        cout << 0 << endl;
    }
    else{
        sum /= k;
        Try(1, 0, 0);
        cout << res << endl;
    }
}