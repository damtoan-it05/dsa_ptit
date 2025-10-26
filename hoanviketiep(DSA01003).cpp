#include<bits/stdc++.h>
using namespace std;
void reverse(int a[], int l, int r) {
	while(l<r) {
		int tmp= a[l];
		a[l]=a[r];
		a[r]=tmp;
		l++;
		r--;
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, ok=1;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		int i = n - 2;
		while(i >= 0 && a[i] >= a[i + 1]) i--;// tim vi tri can doi

		if(i >= 0) {
			int j = n - 1;
			while(a[j] <= a[i]) j--;
			swap(a[i], a[j]);
		}
		reverse(a, i + 1, n - 1);

		for(int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}