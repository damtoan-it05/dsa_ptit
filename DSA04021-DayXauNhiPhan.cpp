#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long f[100];
void ktao(){
	f[1]=f[2]=1;
	for(int i=3;i<93;i++){
		f[i]=f[i-1]+f[i-2];
	}
}
void NP(int n, long long k){
	if(n==1){
		cout << "0" << endl;
		return;
	}
	if(n==2){
		cout << "1" << endl;
		return;
	}
	if(k>f[n-2]) NP(n-1,k-f[n-2]);
	else NP(n-2,k);
}
int main(){
	ktao();
	int t;
	cin >> t;
	while(t--){
		int n;long long k;
		cin >> n >> k;
		NP(n,k);
	} 
}