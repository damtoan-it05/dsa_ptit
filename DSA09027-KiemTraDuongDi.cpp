#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
void BFS(vector<vector<int>> ds,int u,vector<bool> &visited,int pre[]){
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		//cout << s << " ";
		for(int t:ds[s]){
			if(!visited[t]){
				q.push(t);
				visited[t]=true;
				pre[t]=s;
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		// 1. bieu dien do thi
		int V,E;
		cin >> V >> E;
		vector<vector<int>> ds(V+1);
		int pre[1005];
		for(int i=0;i<E;i++){
			int u,v;
			cin >> u >> v;
			ds[u].push_back(v);
			ds[v].push_back(u);
		}
		// duyet bfs
		int n;
		cin >> n;
		int x,y;
		while(n--){
			cin >> x >> y;
			vector<bool> visited(V+1,false);
		    memset(pre,0,sizeof(pre));
			BFS(ds,x,visited,pre);
			if(pre[y]==0){
				cout << "NO" << endl; 
			}
			else{
				cout << "YES" << endl;
			}
		}
	}
}