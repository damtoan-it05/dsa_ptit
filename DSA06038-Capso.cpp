#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
int merge(int a[], int l, int r, int mid) {
	vector<int> c;
	int res = 0;
	int i = l;
	int j = mid + 1;

	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) c.push_back(a[i++]);
		else {
			c.push_back(a[j++]);
			res += (mid - i + 1);
		}
	}
	while (i <= mid) c.push_back(a[i++]);
	while (j <= r) c.push_back(a[j++]);
	for (int i = l; i <= r; i++) a[i] = c[i - l];
	return res;
}
int merge_sort(int a[], int l, int r) {
	int res = 0;
	if (l < r) {
		int mid = (l + r) / 2;
		res += merge_sort(a, l, mid);
		res += merge_sort(a, mid + 1, r);
		res += merge(a, l, r, mid);
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	int a[100001];
	int c[100001];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			c[idx++] = a[i];
		}
	}
	int total = merge_sort(c, 0, idx - 1);
	int cnt = 0;
	a[n] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0 && a[i - 1] % 2 == 0) cnt++;
		else if (a[i] % 2 == 1 && a[i - 1] % 2 == 0) {
			total -= merge_sort(a, i - (cnt + 1), i - 1);
			cnt = 0;
		}
	}
	cout << total << endl;
	return 0;
}