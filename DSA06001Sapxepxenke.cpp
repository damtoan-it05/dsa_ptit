#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[10],b[n];
		for(int i=0; i<n; i++) {
			cin >> b[i];
		}
		sort(b,b+n);
		int l=0,r=n-1;
		while(l<r){
			cout << b[r] << " " << b[l] << " ";
			l++;r--;
		}
		if(n%2==1){
			cout << b[r] << " ";
		}
		cout << endl;
	}
}