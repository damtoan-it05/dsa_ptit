#include<bits/stdc++.h>
using namespace std;
void sinh(int a[], int n){
	while(true){
		int i=n-1,cnt=1;
		while(i>=0&&a[i]==1) i--;
		if(i<0) break;
		a[i]++;
		for(int j=i+1;j<n;j++){
			a[j]=0;
		}
		for(int j=0;j<n-1;j++){
			if(a[j]==a[j+1]&&a[j]==1){
				cnt=0;
				break;
			}
		}
		if(a[0]==1&&a[n-1]==0&&cnt){
			for(int j=0;j<n;j++){
				if(a[j]){
					cout << 'H';
				}
				else cout << 'A';
			}
			cout << endl;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=0;
		}
		sinh(a,n);
	}
}