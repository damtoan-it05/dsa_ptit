#include<bits/stdc++.h>
using namespace std;
int n,k;
int check(int a[],int b[]){
	for(int i=0;i<k;i++){
		if(a[i]!=b[i]) return 1;
	}
	return 0;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int cnt=1;
		cin >> n >> k;
		int a[k],b[k];
		for(int i=0;i<k;i++){
			cin >> a[i];
			b[i]=i+1;
		}
		while(check(a,b)){
			int i=k-1;
			while(i>=0&&b[i]==n-k+i+1) i--;
			b[i]++;
			for(int j=i+1;j<k;j++){
				b[j]=b[j-1]+1;
			}
			cnt++;
		}
		cout << cnt << endl;
	}
}