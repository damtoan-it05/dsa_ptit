#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
			b[i]=a[i];
		}
		sort(a,a+n);
		int l=0,r=n-1;
		while(1){
			if(a[l]!=b[l]) break;
			else l++;
		}
		while(1){
			if(a[r]!=b[r]) break;
			else r--;
		}
		cout << l+1 << " " << r+1 << endl;
	}
	return 0;
}