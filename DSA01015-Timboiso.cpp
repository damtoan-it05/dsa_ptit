#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long so(){
	long long s=0;
	for(int x : v){
		s=s*10+x;
	}
	return s;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		v.push_back(9);
		long long res=so();
		while(1){
			int i=v.size()-1;
			while(i>=0&&v[i]==9) i--;
			if(i<0){
				v.insert(v.begin(), 0);
                i = 0;
			}
			v[i]=9;
			for(int j=i+1;j<v.size();j++){
				v[j]=0;
			}
			res=so();
			if(res%n==0) break;
		}
		cout << res << endl;
		v.clear();
	}
}