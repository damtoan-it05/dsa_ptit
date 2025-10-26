#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[25];
void ktao(){
	k=1;
	a[1]=n;
	cout << "(" << n << ") ";
}
void sinh(){
	while(true){
		int i=k;
		while(i>0&&a[i]==1) i--;
		if(i==0) break;
		else{
			a[i]--;
			int d=k-i+1;
			k=i;
			int q=d/a[i];
			int r=d%a[i];
			if(q){
				for(int j=1;j<=q;j++){
					k++;
					a[k]=a[i];
				}
			}
			if(r){
				k++;
				a[k]=r;
			}
		}
		cout <<"(";
		for(int i=1;i<=k;i++){
			cout << a[i];
			if(i==k) cout << ") ";
			else cout << " ";
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		ktao();
		sinh();
		cout << endl;
	}
}