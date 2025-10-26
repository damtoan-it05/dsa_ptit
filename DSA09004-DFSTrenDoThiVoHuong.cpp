#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void DFS(vector<vector<int>> ds,int u,vector<bool> &visited){
	// c1 dung de quy
//	visited[u]=true;
//	cout << u << " ";
//	for(int i:ds[u]){
//		if(!visited[i]){
//			DFS(ds,i,visited);
//		}
//	}
	//c2 dung stack
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int s=st.top();
		st.pop();
		if(!visited[s]){
			visited[s]=true;
			cout << s << " ";
		}
		for(int t:ds[s]){
			if(!visited[t]){
				st.push(s);
				st.push(t);
				break;
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
		// duyet dfs
		vector<bool> visited(V+1,false);
		DFS(ds,x,visited);
		cout << endl;
	}
}