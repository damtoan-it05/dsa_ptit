#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mod= 1e9+7;
long long luythua(long long n, long long k) {
    if (k == 0) return 1;
    long long x = luythua(n, k / 2);
    if (k % 2 == 0) return (x * x) % mod;
    return (n * ((x * x) % mod)) % mod;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string tmp=s;
		reverse(tmp.begin(),tmp.end());
		long long res=stoll(s),n=stoll(tmp);
		cout << luythua(res,n);
		cout << endl;	
	} 
}