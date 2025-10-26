#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
    	int n, m;
    	cin >> n >> m;
    	int a[n], b[m];
    	for(auto &x : a) cin >> x;
    	for(auto &x : b) cin >> x;
    	map<int,int> mp;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			mp[i+j] += a[i] * b[j]; 
			}
		}
		for(int i = 0; i <= (m + n - 2); i++){
			cout << mp[i] << " ";
		}
		cout << endl;
	}
}