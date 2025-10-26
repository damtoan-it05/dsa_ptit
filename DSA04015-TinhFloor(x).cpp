#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int *it = lower_bound(a,a+n,k);
		if(it==a+n){
			cout << a[n-1] << endl;
			continue;
		}
		else if(*it > k){
			if(*it == a[0]){
				cout << "-1" << endl;
				continue;
			}
			it--;
		}
		for(int i=0;i<n;i++){
			if(*it==a[i]){
				cout << i+1 << endl;
				break;
			}
		}
	} 
}