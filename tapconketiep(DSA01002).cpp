#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k,cnt=1;
		cin >> n >> k;
		int a[k];
		for(int i=0; i<k; i++) {
			cin >> a[i];
		}
		for(int i=k-1; i>=0; i--) {
			int tmp=n-k+i;
			if(a[i]!=tmp+1) {
				a[i]++;
				for(int j=i+1; j<k; j++) {
					a[j]=a[j-1]+1;
				}
				break;
			}
			else a[i]=i+1;
		}
		for(int i=0; i<k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}