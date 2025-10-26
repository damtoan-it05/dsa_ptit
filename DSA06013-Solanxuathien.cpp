#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k,tmp,cnt=0;
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> tmp;
			if(tmp==k) cnt++;
		}
		if(cnt==0){
			cout << "-1" << endl;
		}
		else cout << cnt << endl;
	}
}