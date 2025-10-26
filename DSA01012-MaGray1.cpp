#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
void Gray() {
	cout << a[0];
	for(int j=1; j<n; j++) {
		if(a[j]==a[j-1]){
			cout << "0";
		}
		else cout << "1";
	}
	cout << " ";
}
void sinh() {
	for(int i=0; i<n; i++) {
		cout << 0;
	}
	cout << " ";
	while(true) {
		int i=n-1;
		while(i>=0&&a[i]==1) i--;
		if(i<0) break;
		a[i]=1;
		for(int j=i+1; j<n; j++) {
			a[j]=0;
		}
		Gray();
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) {
			a[i]=0;
		}
		sinh();
		cout << endl;
	}
}