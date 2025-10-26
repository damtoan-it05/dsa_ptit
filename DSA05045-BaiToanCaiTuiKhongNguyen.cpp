#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    double x = 1.0 * a.first / a.second;
    double y = 1.0 * b.first / b.second;
    return x > y;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, w;
        cin >> n >> w;
        pair<int,int> a[n];
        for(auto &x : a){
            cin >> x.first >> x.second;
        }
        sort(a, a + n, cmp);
        double value = 0;
        int weight = 0;
        for(auto x : a){
            if((weight + x.second) <= w){
                value += 1.0 * x.first;
                w -= x.second;
            }
            else{
                int tmp = w - weight;
                value += x.first * (1.0 * tmp / x.second);
                break;
            }
        }
        cout << fixed << setprecision(2) << value << endl;
    }
}