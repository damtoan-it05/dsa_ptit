#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k, a[15],x[15];
vector<string>v;
void result() {
	string s="";
	s+="[";
	for(int i=1; i<=n; i++) {
		if(x[i]) s += to_string(a[i])+" ";
	}
	s.pop_back();
	s+="]";
	v.push_back(s);
}
void Try(int i) {
	for(int j=0; j<=1; j++) {
		x[i]=j;
		if(i==n) {
			int su=0;
			for(int h=1; h<=n; h++) {
				if(x[h]) su+= a[h];
			}
			if(su==k) result();
		} else Try(i+1);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=1; i<=n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		Try(1);
		if(v.empty()) cout << "-1" << endl;
		else{
			for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
			cout << endl;
		}
		v.clear();
	}
}