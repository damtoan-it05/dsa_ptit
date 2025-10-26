#include<iostream>
#include<algorithm>
using namespace std;
long long a[1001][1001],mod=1e9+7;
long long C(long long n,long long k){
	a[1][0]=1;a[1][1]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||i==j) a[i][j]=1;
			else a[i][j]=(a[i-1][j-1]+a[i-1][j])%mod;
		}
	}
	return a[n][k];
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		cout << C(n,k) << endl;
	}
}