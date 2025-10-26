#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n,k,cnt=0;
		cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int tmp=a[i]+a[j];
				if(tmp==k) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}