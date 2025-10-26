#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, k, a[maxn], visited[maxn], sum = 0;
bool check = false;

void init(){
    memset(visited, 0, sizeof(visited));
    sum = 0;
    check = false;
}

void Try(int i, int pos, int val, int cnt){
    if(check){
        return;
    }
    if(cnt == k){
        check = true;
        return;
    }
    for(int j = pos; j <= n; j++){
        if((!visited[j]) and (val + a[j] <= sum)){
            visited[j] = 1;
            val += a[j];
            if(val == sum){
                Try(i + 1, 1, 0, cnt + 1);
            }
            else{
                Try(i + 1, j + 1, val, cnt);
            }
            val -= a[j];
            visited[j] = 0;
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        init();
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if((sum % k) != 0){
            cout << 0 << endl;
        }
        else{
            sum /= k;
            Try(1, 1, 0, 0);
            cout << check << endl;
        }
    }
}