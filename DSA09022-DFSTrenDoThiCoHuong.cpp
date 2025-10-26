#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int cx[1005];
void DFS(int s,vector<int> vt[]){
	cout << s << " ";
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			DFS(c,vt);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int v,e,s;
		cin >> v >> e >> s;
		vector<int> vt[v+1];
		memset(cx,1,sizeof(cx));
		for(int i=1; i<=e; i++) {
			int x,y;
			cin >> x >> y;
			vt[x].push_back(y);
		}
		DFS(s,vt);
		cout << endl;
	}
	return 0;
}