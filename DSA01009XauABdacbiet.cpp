#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<string> v;
void luu(int a[]) {
	string s;
	for(int i=0; i<n; i++) {
		s= s + char(a[i]+'A');
	}
	v.push_back(s);
}
bool check(int a[]) {
	int da=0,dl=0;
	for(int i=0; i<n; i++) {
		if(a[i]==0) {
			da++;
		} 
		else da=0;
		if(da>k) return false;
		if(da==k) dl++;
	}
	return dl==1;
}
void sinh(int a[]) {
	while(true) {
		int i=n-1;
		while(i>=0&&a[i]==1) {
			a[i]=0;
			i--;
		}
		if(i<0) break;
		a[i]=1;
		if(check(a)) {
			luu(a);
		}
	}
}
int main() {
	cin >> n >>k;
	int a[n];
	for(int i=0; i<n; i++) {
	    a[i]=0;
	}
	sinh(a);
	cout << v.size() << endl;
	for(auto x:v) {
		cout << x << endl;
	}
}