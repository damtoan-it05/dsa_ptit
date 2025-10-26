#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n,m,tmp;
		cin >> n >> m;
		set<int> giao,hop;
		for(int i=0;i<n;i++){
			cin >> tmp;
			hop.insert(tmp);
		}
		for(int i=0;i<m;i++){
			cin >> tmp;
			if(hop.find(tmp)!=hop.end()) giao.insert(tmp);
			hop.insert(tmp);
		}
		for(auto x : hop){
			cout << x << " ";
		}
		cout << endl;
		for(auto x : giao){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}