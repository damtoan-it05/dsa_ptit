#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int n,k,b[20][20];
vector<int> a;
void ktao() {
	for(int i=0; i<n; i++) {
		a.push_back(i+1);
	}
}
void sinh() {
	do{
		int s=0;
		for(int i=0; i<n; i++) {
			s+=b[i][a[i]-1];
		}
		if(s==k) v.push_back(a);
	}while(next_permutation(a.begin(),a.end()));
}
int main() {
	cin >> n >> k;
	ktao();
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> b[i][j];
		}
	}
	sinh();
	cout << v.size() << endl;
	for(auto it : v) {
		for(int x : it) {
			cout << x << " ";
		}
		cout << endl;
	}
}