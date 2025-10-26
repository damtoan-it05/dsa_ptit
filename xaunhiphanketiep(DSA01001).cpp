#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin.ignore();
		string s;
		cin >> s;
		int n=s.size();
		int a[n];
		for(int i=0; i<n; i++) {
			a[i]=s[i]-'0';
		}
		int j=n-1;
		while(j>=0&&a[j]>0) {
			a[j]=0;
			j--;
		}
		if(j<0) {
			for(int i=0; i<n; i++) {
				cout << a[i];
			}
		}
		else {
			a[j]=1;
			for(int i=0; i<n; i++) {
				cout << a[i];
			}
		}
		cout << endl;
	}
}