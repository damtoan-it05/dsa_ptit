#include<bits/stdc++.h>
using namespace std;
int n,a[1005];
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		n=s.size();
		cout << s[0];
		for(int i=1; i<n; i++) {
			if(s[i]==s[i-1]){
				cout << '0';
			}
			else cout << '1';
		}
		cout << endl;
	}
}