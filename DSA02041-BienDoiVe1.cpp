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
        queue<pair<int,int>> Q;
        Q.push({n, 0});
        while(1){
            pair<int,int> x = Q.front(); Q.pop();
            if(x.first == 1){
                cout << x.second << endl;
                break;
            }
            if(x.first % 2 == 0){
                Q.push({x.first / 2, x.second + 1});
            }
            if(x.first % 3 == 0){
                Q.push({x.first / 3, x.second + 1});
            }
            Q.push({x.first - 1, x.second + 1});
        }
    }
}