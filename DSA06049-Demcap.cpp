#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
	  int a[n];
		for(auto &i : a) cin >> i;
		sort(a,a+n);
		long long cnt=0;
		for(int i=0;i<n;i++){
			cnt+=lower_bound(a+i+1,a+n,a[i]+k)-(a+i+1);
		}
		cout << cnt << endl;
	}
}