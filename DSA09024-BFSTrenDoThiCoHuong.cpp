#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int cx[1005];
void BFS(int s,vector<int> vt[]){
	cout << s << " ";
	cx[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i:vt[x]){
			if(cx[i]){
				cout << i << " ";
				q.push(i);
				cx[i]=0;
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int v,e,s;
		cin >> v >> e >> s;
		vector<int> vt[v+1];
		memset(cx,1,sizeof(cx));
		for(int i=1; i<=e; i++) {
			int x,y;
			cin >> x >> y;
			vt[x].push_back(y);
		}
		BFS(s,vt);
		cout << endl;
	}
	return 0;
}