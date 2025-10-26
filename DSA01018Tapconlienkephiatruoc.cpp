#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005]={0};
void sinhnguoc() {
	int i=k;
	while(i>0&&a[i]==a[i-1]+1) i--;
	if(i==0) {
		for(int j=1; j<=k; j++) {
			cout << (n-k+j) << " ";
		}
	} 
	else {
		a[i]--;
		for(int j=i+1; j<=k; j++) {
			a[j]=n-k+j;
		}
		for(int j=1; j<=k; j++) {
			cout << a[j] << " ";
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=1; i<=k; i++) {
			cin >> a[i];
		}
		sinhnguoc();
		cout << endl;
	}
}