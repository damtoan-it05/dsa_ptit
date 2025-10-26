#include<bits/stdc++.h>
using namespace std;
int n;
int check(int a[],int b[]){
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) return 1;
	}
	return 0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int cnt=1;
		cin >> n;
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
			b[i]=i+1;
		}
		while(check(a,b)){
			next_permutation(b,b+n);
			cnt++;
		}
		cout << cnt << endl;
	}
}