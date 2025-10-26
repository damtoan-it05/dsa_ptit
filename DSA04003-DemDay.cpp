#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mod= 123456789;
long long luythua(long long n,long long k){
	long long res=1;
	while(k){
		if(k%2){
			res=res*n%mod;
		}
		k/=2;
		n=n*n%mod;
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		cout << luythua(2,n-1) <<  endl;	
	} 
}