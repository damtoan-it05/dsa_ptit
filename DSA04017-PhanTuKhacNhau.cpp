#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long x;
		long long a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int s,ok=1;
		for(int i=0;i<n-1;i++){
			cin >> x;
			if(x!=a[i]&&ok){
				s=i+1;
				ok=0;
			}
		}
		cout << s << endl;
	} 
}