#include<bits/stdc++.h>
using namespace std;
bool search(int a[], int i, int n){
	int cnt=1;
	for(int j=i+1; j<n; j++) {
		if(a[i]==a[j]){
			cnt++;
		}
	}
	if(cnt>(n)/2) return true;
	return false;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		int ok=1;
		for(int i=0; i<n; i++){
			if(search(a,i,n)){
				ok=0;
				cout << a[i] << endl;
				break;
			}
		}
		if(ok) cout << "NO" << endl;
	}
	return 0;
}