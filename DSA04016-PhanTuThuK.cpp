#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		int x;
		vector<int> v;
		for(int i=0;i<n;i++){
			cin >> x;
			v.push_back(x);
		}
		for(int i=0;i<m;i++){
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		cout << v[k-1] << endl;
	} 
}