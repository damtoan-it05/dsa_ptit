#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int v,e,u,cx[1005];
vector<int> K[1005];
vector<pair<int,int>> vt;
void ktao(){
	memset(cx,1,sizeof(cx));
	for(int i=1;i<=v;i++){
		K[i].clear();
	}
	vt.clear();
}
void BFS(int s){
	cx[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i:K[x]){
			if(cx[i]){
				vt.push_back({x,i});
				cx[i]=0;
				q.push(i);
			}
		}
	}
}
void Test(){
	ktao();
	cin >> v >> e >> u;
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		K[x].push_back(y);
		K[y].push_back(x);
	}
	BFS(u);
	if(vt.size()!=v-1) cout << -1;
	else{
		for(auto it:vt){
			cout << it.first << " " << it.second << endl;
		}
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}