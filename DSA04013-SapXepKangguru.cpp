#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n+1];
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int i = n/2, j = n, cnt = 0;
        while((i >= 1) and (j >= (n/2 + 1))){
            if(a[j] >= 2 * a[i]){
                --i;
                --j;
            }
            else{
                --i;
            }
            ++cnt;
        }
        while(i >= 1){
            ++cnt;
            --i;
        }
        while(j >= (n/2 + 1)){
            ++cnt;
            --j;
        }
        cout << cnt << endl;
    }
}