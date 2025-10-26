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
		for(int i=1; i<n; i++) {
			if(s[i]=='0'){
				s[i] = s[i-1];
			}
			else{
				if(s[i-1]=='0'){
					s[i] = '1';
				}
				else s[i] = '0';
			}
		}
		cout << s << endl;
	}
}