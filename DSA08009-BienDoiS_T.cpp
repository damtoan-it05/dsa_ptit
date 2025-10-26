#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int m,n;
		cin >> n >> m;
		queue<pair<int,int>> q;
		q.push({n,0});
		unordered_map<int,int> mp;
		while(!q.empty()) {
			auto tmp=q.front(); q.pop();
			if(tmp.first>=1) {
				if(tmp.first-1==m){
					cout << tmp.second+1 << endl;
					break;
				}
				else if(mp[tmp.first-1]==0){
					mp[tmp.first-1]=1;
					q.push({tmp.first-1,tmp.second+1});
				}
			} 
			if(tmp.first<=m) {
				if(2*tmp.first==m){
					cout << tmp.second+1 << endl;
					break;
				}
				else if(mp[2*tmp.first]==0){
					mp[2*tmp.first]=1;
					q.push({2*tmp.first,tmp.second+1});
				}
			}
		}
	}
}