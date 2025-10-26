#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k,x;
		cin >> n >> k;
		map<int,int> mp;
		long long cnt=0;
		for(int i=0; i<n; i++) {
			cin >> x;
			cnt+=mp[k-x];
			mp[x]++;
		}
		cout << cnt << endl;
	}
}