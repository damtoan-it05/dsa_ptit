#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int M=1e5+5;
int n,m;
vector<int> vt[M];
int cx[M];
int BFS(int s,int cnt) {
	cx[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		cnt++;
		for(int c:vt[x]) {
			if(cx[c]) {
				cx[c]=0;
				q.push(c);
			}
		}
	}
	return cnt;
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
	int tmp, res=0;
	for(int i=1; i<=n; i++) {
		if(cx[i]) {
			tmp=BFS(i,0);
			res=max(tmp,res);
		}
	}
	cout << res << endl;
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