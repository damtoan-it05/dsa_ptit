#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,cx[1005];
vector<int> vt[1005];
void DFS(int s){
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			DFS(c);
		}
	}
}
bool Connected(int x){
	int tplt=0;
	memset(cx,1,sizeof(cx));
	cx[x]=0;
	for(int i=1;i<=v;i++){
		if(cx[i]){
			tplt++;
			DFS(i);
		}
	}
	return tplt>1;
}
void Test(){
	cin >> v >> e;
	for(int i=1;i<=v;i++){
		vt[i].clear();
	}
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(int i=1;i<=v;i++){
		if(Connected(i)){
			cout << i << " ";
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