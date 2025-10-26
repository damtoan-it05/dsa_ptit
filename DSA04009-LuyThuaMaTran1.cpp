#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int n,k;
ll d[11][11],mod=1e9+7;
void mul(ll a[11][11], ll b[11][11]){
	ll c[11][11]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int h=0;h<n;h++){
				c[i][j]+=a[i][h]*b[h][j];
				c[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = c[i][j];
		}
	}
}
void nhan(ll a[11][11], int k){
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
		ll a[11][11];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a[i][j];
				d[i][j]=a[i][j];
			}
		}
		nhan(a,k);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}