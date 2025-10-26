#include<iostream>
#include<vector>
#include<cstring>
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
void DFS(int s){
	cx[s]=0;
	for(int c:K[s]){
		if(cx[c]){
			vt.push_back({s,c});
			DFS(c);
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
	DFS(u);
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