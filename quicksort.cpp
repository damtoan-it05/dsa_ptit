#include<bits/stdc++.h>
using namespace std;
void Quicksort(int a[],int l, int r) {
	int i=l,j=r;
	int mid=(r+l)/2;
	do {
		while(a[i]<a[mid] && i<r) i++;
		while(a[j]>a[mid] && j >l) j--;
		if(i<=j) {
			swap(a[i],a[j]);
			i++;
			j--;
		}
	} while(i<=j);
	if(l<j) Quicksort(a,l,j);
	if(i<r) Quicksort(a,i,r);
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		Quicksort(a,0,n-1);
		for(int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}