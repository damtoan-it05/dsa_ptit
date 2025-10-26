#include<iostream>
#include<algorithm>
using namespace std;
long long mod=1e9+7;
long long n,k;
long long luythua(){
	long long res=1;
	while(k){
		if(k%2){
			res=res*n%mod;
		}
		k/=2;
		n*=n;
		n%=mod;
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		long long s=luythua();
		cout << s << endl;
	}
}