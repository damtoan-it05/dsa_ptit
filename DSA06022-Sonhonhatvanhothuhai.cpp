#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a, n1=1e9,n2=1e9;
		for(int i=0;i<n;i++){
			cin >> a;
			if(a<n1){
			  n2=n1;
			  n1=a;
			}
			else if(a<n2) n2=a;
		}
		if(n2==n1) cout << "-1" << endl;
		else cout << n1 << " " << n2 << endl;
	}
}