#include<bits/stdc++.h>
using namespace std;
int n,k;
void sinh(int a[]) {
	for(int i=0; i<k; i++) {
			cout << a[i];
		}
	cout << " ";
	while(true){
		int i=k-1;
    	while(i>=0 && a[i]==n-k+i+1) i--;
    	if(i<0) break;
		a[i]++;
		for(int j=i+1; j<k; j++) {
			a[j]=a[j-1]+1;
		}
		for(int i=0; i<k; i++) {
				cout << a[i];
			}
		cout << " ";
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int a[k];
		for(int i=0; i<k; i++) {
			a[i]=i+1;
		}
		sinh(a);
		cout << endl;
	}
}