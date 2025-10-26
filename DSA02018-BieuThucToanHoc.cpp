#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 100;

int a[maxn], idx[maxn];
char KiTu[3] = {'+', '-', '*'}, X[maxn];

int Tinh_Toan(int x, int y, char c){
    if(c == '+'){
        return x + y;
    }
    else if(c == '-'){
        return x - y;
    }
    return x * y;
}

bool check = true;

void Try(int i){
    if(!check) return;
    for(int j = 0; j <= 2; j++){
        X[i] = KiTu[j];
        if(i == 4){
            int n1 = Tinh_Toan(a[idx[1]], a[idx[2]], X[1]);
            int n2 = Tinh_Toan(n1, a[idx[3]], X[2]);
            int n3 = Tinh_Toan(n2, a[idx[4]], X[3]);
            int n4 = Tinh_Toan(n3, a[idx[5]], X[4]);
            if(n4 == 23){
                check = false;
                return;
            }
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        for(int i = 1; i <= 5; i++){
            cin >> a[i];
            idx[i] = i;
        }
        check = true;
        do{
            if(!check) break;
            Try(1);
        } while(next_permutation(idx + 1, idx + 6));
        if(check){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}