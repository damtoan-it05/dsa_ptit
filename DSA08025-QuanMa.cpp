#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int a[10][10],cx[10][10];
int dx[8]= {-2,-2,-1,-1,1,1,2,2};
int dy[8]= {-1,1,-2,2,-2,2,-1,1};
struct Node {
	int x,y;
	int idx;
};
void Test() {
	string u,v;
	int s,t,e,n;
	cin >> u >> v;
	queue<Node> q;
	s=int(u[0]-'a');t=u[1]-'0';
	e=int(v[0]-'a');n=v[1]-'0';
	q.push({s,t,0});
	memset(cx,1,sizeof(cx));
	cx[s][t]=0;
	while(!q.empty()) {
		Node tmp=q.front();
		q.pop();
		int i=tmp.x,j=tmp.y;
		if(i==e && j==n) {
			cout << tmp.idx << endl;
			cx[i][j]=0;
			return;
		}
		for(int k=0; k<8; k++) {
			int r1=i+dx[k];
			int r2=j+dy[k];
			if(r1==e && r2==n) {
				cout << tmp.idx+1 << endl;
				cx[r1][r2]=0;
				return;
			} else if(r1<=8&&r1>=1 && r2<=8&&r2>=1 && cx[r1][r2]) {
				q.push({r1,r2,tmp.idx+1});
				cx[r1][r2]=0;
			}
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		Test();
	}
}