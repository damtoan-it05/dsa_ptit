#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
ll mod=1e9+7;
ll a[11][11],d[11][11];
int n,k;
void mul(long long x1[11][11],long long x2[11][11]){
	ll x[11][11]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int h=0;h<n;h++){
				x[i][j]+=x1[i][h]*x2[h][j];
				x[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=x[i][j];
		}
	}
}
void nhan(long long a[11][11], int k){
	if(k==1) return;
	nhan(a,k/2);
	mul(a,a);
	if(k%2) mul(a,d);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
				d[i][j]=a[i][j];
			}
		}
		nhan(a,k);
		ll s=0;
		for(int i=0;i<n;i++){
			s+=a[i][n-1];
			s%=mod;
		}
		cout << s << endl;
	}
}