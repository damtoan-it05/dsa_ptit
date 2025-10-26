#include<bits/stdc++.h>
using namespace std;
int n, k;
void sinh(int a[]) {
	while(true){
			int cnt=0,i=n-1;
	while(i>=0 && a[i]==1) i--;
	if(i<0) break;
	a[i]++;
	for(int j=i+1; j<n; j++) {
		a[j]=0;
	}
	for(int j=0; j<n; j++) {
		if(a[j]==1) cnt++;
	}
	if(cnt==k) {
		for(int j=0; j<n; j++) {
			cout << a[j];
		}
		cout << endl;
	}
	}
	
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int a[n];
		for(int i=0; i<n; i++) {
			a[i]=0;
		}
		sinh(a);
	}
}