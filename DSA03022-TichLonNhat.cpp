#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t=1;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		int s=0;
		s=max(s,a[0]*a[1]);
		s=max(s,a[0]*a[1]*a[n-1]);
		s=max(s,a[n-1]*a[n-2]*a[n-3]);
		s=max(s,a[n-1]*a[n-2]);
		cout << s;
	} 
}