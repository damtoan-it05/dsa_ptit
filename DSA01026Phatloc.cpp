#include<bits/stdc++.h>
using namespace std;
void sinh(int a[],int n) {
	while(true) {
		int i=n-1,cnt=1,c=0;
		while(i>=0&&a[i]==1) i--;
		if(i<0) break;
		a[i]++;
		for(int j=i+1; j<n; j++) {
			a[j]=0;
		}
		for(int j=0; j<n-1; j++) {
			if(a[j]==a[j+1]&&a[j]==1) {// ko co 2 so 8 canh nhau
				cnt=0;
				break;
			}
		}
		for(int j=n-1; j>=0; j--) {// nhieu nhat 3 so 6 canh nhau
			while(a[j]==0) {
				c++;
				j--;
			}
			if(c>3) {
				cnt=0;
				break;
			} 
			else c=0;
		}
		if(cnt&&a[0]==1&&a[n-1]==0) {
			for(int i=0; i<n; i++) {// in ra neu du dk
				if(a[i]) {
					cout << '8';
				} 
				else cout << '6';
			}
			cout << endl;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
		a[i]=0;
	}
	sinh(a,n);
}