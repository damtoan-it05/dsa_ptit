#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	m=(n+1)/2;
	vector<int> v(m,0);
	while(true) {
		for(int j=0; j<m; j++) {
			cout << v[j] << " ";
		}
		for(int j=m-1; j>=0; j--) {
			cout << v[j] << " ";
		}
		cout << endl;
		int i=m-1;
		while(i>=0 && v[i]==1){
			v[i]=0;
			i--;
		}
		if(i<0) break;
		v[i]=1;
	}
}