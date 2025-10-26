#include<iostream>
#include<algorithm>
using namespace std;
long long mod=1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long a[n],s=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			s+=a[i]*i;
			s%=mod;
		}
		cout << s << endl;
	}
}