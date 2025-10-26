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
		int a[n],s=0,res=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n;i++){
			s+=a[i];
			if(s<0) s=0;
			if(s>res) res=s;
		}
		cout << res << endl;
	}
}