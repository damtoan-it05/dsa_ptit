#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int cx[1005],pre[1005],v,e;
vector<int> vt[1005];
void BFS(int s){
	cx[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int c:vt[x]){
			if(cx[c]){
				cx[c]=0;
				q.push(c);
			}
		}
	}
}
void Connected(){
	int tplt=0;
	memset(cx,1,sizeof(cx));
	for(int i=1;i<=v;i++){
		if(cx[i]){
			tplt++;
			BFS(i);
		}
	}
	cout << tplt << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> v >> e;
		for (int i = 1; i <= v; i++){
			vt[i].clear();
		}
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		Connected();
	}
}