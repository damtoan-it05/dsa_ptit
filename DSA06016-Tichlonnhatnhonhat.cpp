#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,m;
		cin >> n >> m;
		long long maxx=-1e9,s=1,x;
		for(int i=0;i<n;i++){
			cin >> x;
			if(x > maxx) maxx=x;
		}
		s*=maxx;
		for(int i=0;i<m;i++){
			cin >> x;
			if(x < maxx) maxx=x;
		}
		s*=maxx;
		cout << s << endl;
	}
}