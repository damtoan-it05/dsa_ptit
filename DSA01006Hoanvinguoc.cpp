#include<bits/stdc++.h>
using namespace std;
int n;
void hoanvinguoc(int a[]){
	do{
		for(int i=0; i<n; i++) {
			cout << a[i];
		}
		cout << " ";
	}while(prev_permutation(a,a+n));
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=n-i;
		}
		hoanvinguoc(a);
		cout << endl;
	}
}