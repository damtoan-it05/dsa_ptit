#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void BFS(vector<vector<int>> ds,int u,vector<bool> &visited){
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		cout << s << " ";
		for(int t:ds[s]){
			if(!visited[t]){
				q.push(t);
				visited[t]=true;
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		// 1. bieu dien do thi
		int V,E,x;
		cin >> V >> E >> x;
		vector<vector<int>> ds(V+1);
		for(int i=0;i<E;i++){
			int u,v;
			cin >> u >> v;
			ds[u].push_back(v);
			ds[v].push_back(u);
		}
		// duyet bfs
		vector<bool> visited(V+1,false);
		BFS(ds,x,visited);
		cout << endl;
	}
}