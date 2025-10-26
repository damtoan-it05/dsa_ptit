#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int> vt[1005];
int v,e,cx[1005];
void DFS(int s){
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			DFS(c);
		}
	}
}
int lt(int s) {
	int tplt=0;
	memset(cx,1,sizeof(cx));
	cx[s]=0;
	for(int i=1;i<=v;i++){
		if(cx[i]){
			tplt++;
			DFS(i);
		}
	}
	return tplt;
}
void Test() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		vt[i].clear();
	}
	for(int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	int x=lt(0);
	for(int i=1;i<=v;i++){
		int y=lt(i);
		if(y>x){
			cout << i << " ";
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		Test();
		cout << endl;
	}
	return 0;
}