#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,dx[1005];
vector<int> vt[1005];
bool DFS(int s){
	dx[s]=1;
	for(int c:vt[s]){
		if(!dx[c]){
			if(DFS(c)){
				return true;
			}
		}
		else if(dx[c]==1) return true;
	}
	dx[s]=2;
	return false;
}
void Test(){
	cin >> v >> e;
	for(int i=1;i<=v;i++){
		vt[i].clear();
	}
	memset(dx,0,sizeof(dx));
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
	}
	for(int i=1;i<=v;i++){
		if(!dx[i]){
			if(DFS(i)){
				cout << "YES";
				return;
			}
		}
	}
	cout << "NO";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}