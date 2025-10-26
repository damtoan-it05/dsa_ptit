#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		k=n/2;
		int s=a[0]+a[n-1],ok=1;
		for(int i=0;i<k;i++){
			if(a[i]+a[n-1-i]!=s){
				cout << "No" << endl;
				ok=0;
				break;
			}
		}
		if(ok) cout << "Yes" << endl;
	} 
}