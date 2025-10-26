#include<iostream>
#include<algorithm>
using namespace std;
int n,k,ok=1e6,a[50];
void Min(int i, int s, int cnt) {
	if(s == 0) {
		ok = min(ok, cnt);
		return;
	}
	if(i == n || cnt >= ok) return;

	if(s >= a[i]) Min(i + 1, s - a[i], cnt + 1);

	Min(i + 1, s, cnt);
}

int main() {
	cin >> n >> k;
	for(int j=0; j<n; j++) cin >> a[j];
	sort(a,a+n, greater<int>());
	Min(0,k,0);
	if(ok==1e6) cout << "-1";
	else cout << ok;
}