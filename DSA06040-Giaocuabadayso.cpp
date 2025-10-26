#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n1,n2,n3;
		long long tmp;
		cin >> n1 >> n2 >> n3;
		vector<long long> v1(n1),v2(n2),v3(n3);
		for(auto &i :v1) cin >> i;
		for(auto &i :v2) cin >> i;
		for(auto &i :v3) cin >> i;
		int x=0,y=0,z=0,ok=1;
		while(x<n1&&y<n2&&z<n3){
			if(v1[x]==v2[y]&& v2[y]==v3[z]){
				cout << v1[x] << " ";
				ok=0;
				x++;y++;z++;
			}
			else if(v1[x]<v2[y]) x++;
			else if(v2[y]<v3[z]) y++;
			else z++;
		}
		if(ok) cout << "-1";
		cout << endl;
	}
}