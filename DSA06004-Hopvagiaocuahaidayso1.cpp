#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n,m,tmp;
		cin >> n >> m;
		map<int,int> mp;
		for(int i=0;i<n;i++){
			cin >> tmp;
			mp[tmp]++;
		}
		for(int i=0;i<m;i++){
			cin >> tmp;
			mp[tmp]++;
		}
		for(auto x : mp){
			if(x.second) cout << x.first << " ";
		}
		cout << endl;
		for(auto x : mp){
			if(x.second>1) cout << x.first << " ";
		}
		cout << endl;
	}
	return 0;
}