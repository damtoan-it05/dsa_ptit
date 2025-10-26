#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mod=1e9+7;
int main(){
	long long a, b;
	while(1){
		cin >> a >> b;
		if(!a && !b) break;
		long long res=1;
		while(b){
			if(b%2){
				res=res*a%mod;
			}
			b/=2;
			a*=a;
			a%=mod;
		}
		cout << res << endl;
	}
}