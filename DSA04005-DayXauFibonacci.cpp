#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long f[100];
void ktao(){
	f[1]=f[2]=1;
	for(int i=3;i<93;i++){
		f[i]=f[i-2]+f[i-1];
	}
}
void Try(int n, long long k){
	if(n==1){
		cout << 'A' << endl;
		return;
	}
	if(n==2){
		cout << 'B' << endl;
		return;
	}
	if(k>f[n-2]) Try(n-1,k-f[n-2]);
	else Try(n-2,k);
}
int main(){
	ktao();
	int t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		Try(n,k);	
	} 
}