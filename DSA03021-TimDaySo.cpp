#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = 1;
    }
    while(1){
        bool check = true;
        for(int i = 1; i < n; i++){
            if((a[i]/b[i]) != (a[i-1]/b[i-1])){
                check = false;
                while((a[i]/b[i]) != (a[i-1]/b[i-1])){
                    if((a[i]/b[i]) > (a[i-1]/b[i-1])){
                        ++b[i];
                    }
                    else{
                        ++b[i-1];
                    }
                }
            }
        }
        if(check){
            break;
        }
    }
    int sum = 0;
    for(auto x : b){
        sum += x;
    }
    cout << sum << endl;
}