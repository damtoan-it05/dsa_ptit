#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n;
	string s;
	cin >> n >> s;
	ll total = 1LL * n * (n - 1) / 2;
	ll cnt = 1;
	vector<ll> v;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) cnt++;
		else {
			v.push_back(cnt);
			cnt = 1;
		}
	}
	v.push_back(cnt);
	for (int i = 1; i < v.size(); i++) {
		total -= (v[i] + v[i - 1] - 1);
	}
	cout << total << endl;
	return 0;
}
