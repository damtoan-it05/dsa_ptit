#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;
void Test() {
	int n;
	cin >> n;
	queue<pair<int,int>> q;
	q.push({n,0});
	unordered_map<int,int> mp;
	while(!q.empty()) {
		auto tmp=q.front();
		q.pop();
		if(tmp.first==1) {
			cout << tmp.second+1 << endl;
			return;
		}
		if(tmp.first-1==1) {
			cout << tmp.second+1 << endl;
			return;
		} else {
			mp[tmp.first-1]=1;
			q.push({tmp.first-1,tmp.second+1});
		}
		for(int i=2; i<=sqrt(tmp.first); i++) {
			if(tmp.first%i==0) {
				int x=max(i,tmp.first/i);
				if(x==1) {
					cout << tmp.second+1 << endl;
					return;
				} else if(mp[x]==0) {
					mp[x]=1;
					q.push({x,tmp.second+1});
				}
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		Test();
	}
}