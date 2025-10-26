#include<bits/stdc++.h>
using namespace std;
int n,k,a[40]= {0};
void sinh() {
	for(int i=1; i<=k; i++) {
		cout << char(a[i]+'A'-1);
	}
	cout << endl;
	while(true) {
		int i=k;
		while(i>0&&a[i]==n-k+i) i--;
		if(i<1) break;
		a[i]++;
		for(int j=i+1; j<=k; j++) {
			a[j]=a[j-1]+1;
		}
		for(int j=1; j<=k; j++) {
			cout << char(a[j]+'A'-1);
		}
		cout << endl;
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=1; i<=k; i++) {
			a[i]=i;
		}
		sinh();
	}
}