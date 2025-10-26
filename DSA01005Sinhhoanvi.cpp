#include<bits/stdc++.h>
using namespace std;
int n;
void reverse(int a[], int l, int r) {
	while(l<r) {
		int tmp= a[l];
		a[l]=a[r];
		a[r]=tmp;
		l++;
		r--;
	}
}
void sinhhoanvi(int a[]){
	while(true){
		for(int i=0; i<n; i++) {
			cout << a[i];
		}
		cout << " ";
		int i=n-2;
		while(i>=0 && a[i]>=a[i+1]) i--;
		if(i>=0){
			int j=n-1;
			while(a[j]<=a[i]) j--;
			swap(a[j],a[i]);
		}
		else break;
		reverse(a,i+1,n-1);
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			a[i]=i+1;
		}
		sinhhoanvi(a);
		cout << endl;
	}
}