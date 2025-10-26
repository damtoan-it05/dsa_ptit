#include<bits/stdc++.h>
using namespace std;
void Dequy(int a[], int n){
	if(n==0){
		return;
	}
	else{
		cout << "[";
		for(int i=0;i<n;i++){
			cout << a[i];
			if(i!=n-1) cout << " ";
		}
		cout << "]" << endl;
		for(int i=0;i<n-1;i++){
			a[i]+=a[i+1];
		}
		n--;
		Dequy(a,n);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		Dequy(a,n);
	}
}