#include<bits/stdc++.h>
using namespace std;
long long prime[1000005];
void sang(){
	for(int i=0;i<1000005;i++){
		prime[i]=1;
	}
	prime[0]=0;prime[1]=0;
	for(int i=2;i<=1000;i++){
		if(prime[i]){
			for(int j=i*i;j<1000005;j+=i){
				prime[j]=0;
			}
		}
	}
}
int main(){
	sang();
	int t;
	cin >> t;
	while(t--){
		int n,ok=1;
		cin >> n;
		for(int i=2;i<=n/2;i++){
			if(prime[i] && prime[n-i]){
				cout << i << " " << n-i << endl;
				ok=0;
				break;
			}
		}
		if(ok) cout << "-1" << endl;
	}
}