#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int M=1e5+5;
int n,m;
vector<int> vt[M];
int cx[M];
void BFS(int s) {
	cx[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(int c:vt[x]) {
			if(cx[c]) {
				cx[c]=0;
				q.push(c);
			}
		}
	}
}
void Test() {
	cin >> n >> m;
	memset(cx,1,sizeof(cx));
	for(int i=1;i<=n;i++){
		vt[i].clear();
	}
	for(int i=1; i<=m; i++) {
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	BFS(1);
	bool ok=true;
	for(int i=1; i<=n; i++) {
		if(cx[i]) {
			ok=false;
			break;
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		Test();
	}
}
