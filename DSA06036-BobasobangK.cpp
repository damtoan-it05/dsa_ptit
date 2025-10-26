#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k;
		cin >> n >> k;
		long long a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a,a+n);
		bool f=false;
		for(int i=0; i<n-2; i++) {
			int l=i+1,r=n-1;
			while(l<r) {
				long long s=a[i]+a[l]+a[r];
				if(s>k) r--;
				else if(s==k){
					f=true;
					break;
				}
				else l++;
			}
			if(f){
				cout << "YES" << endl;
				break;
			}
		}
		if(!f) cout << "NO" << endl;
	}
}