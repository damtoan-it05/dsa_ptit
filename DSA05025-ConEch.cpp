#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> f(n+1);
		f[0]=1,f[1]=2,f[2]=4;
		for(int i=3;i<=n;i++){
			f[i]=f[i-1]+f[i-2]+f[i-3];
		}
		cout << f[n-1] << endl;
	}
}