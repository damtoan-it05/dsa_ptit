#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 1e9;
int v,e,s, pre[1005];
vector<pair<int,int>> Ke[1005];

void Dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	vector<int> vt(v+1,INF);
	vt[s]=0;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int> c = q.top();q.pop();
		int u=c.second,kc=c.first;
		if(kc>vt[u]) continue;
		for(auto it:Ke[u]){
			int v=it.first;
			int w=it.second;
			if(vt[v]>vt[u]+w){
				vt[v]=vt[u]+w;
				q.push({vt[v],v});
			}
		}
	}	
	for(int i=1;i<=v;i++){
		cout << vt[i] << " ";
	}
	cout << endl;
}
 
void Test(){
	memset(Ke,0,sizeof(Ke));
	cin >> v >> e >> s;
	for(int i=1;i<=e;i++){
		int x,y,z;
		cin >> x >> y >> z;
		Ke[x].push_back({y,z});
		Ke[y].push_back({x,z});
	}
	Dijkstra();
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}