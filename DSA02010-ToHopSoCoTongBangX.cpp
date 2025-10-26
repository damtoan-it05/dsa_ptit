#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int n, S, a[maxn], X[maxn], sum = 0;
bool check = true;

void input(){
    sum = 0;
    check = true;
    cin >> n >> S;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

void Try(int i, int pos){
    for(int j = pos; j <= n; j++){
        if((sum + a[j]) <= S){
            X[i] = a[j];
            sum += a[j];
            if(sum == S){
                check = false;
                cout << "[";
                for(int l = 1; l <= i; l++){
                    cout << X[l];
                    if(l != i){
                        cout << " ";
                    }
                    else{
                        cout << "]";
                    }
                }
            }
            else{
                Try(i + 1, j);
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
            cout << "-1";
        }
        cout << endl;
    }
}