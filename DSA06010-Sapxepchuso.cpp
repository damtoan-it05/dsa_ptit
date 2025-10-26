#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[10];
		string s;
		while(n--) {
			cin >> s;
			for(int i=0;i<s.size();i++){
				a[s[i]-'0']=1;
			}
		}
		for(int i=0; i<10; i++){
			if(a[i]==1){
				cout << i << " ";
				a[i]=0;
			}
		}
		cout << endl;
	}
	return 0;
}