#include<bits/stdc++.h>
using namespace std;
set<string> se;
vector<string> v;
int n,k,a[40]= {0};
void Try(int i) {
	for(int j=a[i-1]+1; j<=v.size()-k+i; j++) {
		a[i]=j;
		if(i==k) {
			for(int i=1; i<=k; i++) {
				cout << v[a[i]-1] << " ";
			}
			cout << endl;
		} 
		else Try(i+1);
	}
}
int main() {
	cin >> n >> k;
	string s;
	for(int i=0; i<n; i++) {
		cin >> s;
		se.insert(s);
	}
	for(auto x : se) {
		v.push_back(x);
	}
	Try(1);
}