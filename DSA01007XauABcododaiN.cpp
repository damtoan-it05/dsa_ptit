#include<bits/stdc++.h>
using namespace std;
int n;
void sinh(int a[]){
	for(int i=0; i<n; i++) {
		cout << (char)('A'+a[i]);
	}
	cout << " ";
	while(true){
		int i=n-1;
		while(i>=0 && a[i]==1) i--;
		if(i<0) break;
		a[i]++;
		for(int j=i+1;j<n;j++){
			a[j]=0;
		}
		for(int i=0; i<n; i++) {
			cout << (char)('A'+a[i]);
		}
		cout << " ";
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=0;
		}
		sinh(a);
		cout << endl;
	}
}