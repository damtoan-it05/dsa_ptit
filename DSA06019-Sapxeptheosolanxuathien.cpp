#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second) return a.first < b.first;
	else return a.second>b.second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n;
		map<int,int> mp;
		for(int i=0;i<n;i++){
			cin >> x;
			mp[x]++; 
		}
		vector<pair<int,int>> v(mp.begin(),mp.end());
		sort(v.begin(),v.end(),cmp);
		for(auto a : v){
			for(int i=0;i<a.second;i++){
				cout << a.first << " ";
			}
		}
		cout << endl;
	}
}