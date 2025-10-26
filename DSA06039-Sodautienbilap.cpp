#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		map<int, int> mp;
		for(int i=0; i<n; i++) {
			cin >> a[i];
			mp[a[i]]++;
		}
		int ok=1;
		for(int i=0; i<n; i++){
			if(mp[a[i]]==2){
				ok = 0;
				cout << a[i] << endl;
				break;
			}
		}
		if(ok) cout << "NO" << endl;
	}
	return 0;
}