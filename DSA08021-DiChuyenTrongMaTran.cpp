#include<iostream>
#include<queue>
using namespace std;
int a[1005][1005],cx[1005][1005];
struct Node{
	int x,y;
	int idx;
};
int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
				cx[i][j]=1;
			}
		}
		queue<Node> q;
		q.push({1,1,0});
		cx[1][1]=0;
		while(!q.empty()){
			Node tmp=q.front();q.pop();
			int i=tmp.x,j=tmp.y;
			bool ok=false;
			if(i==m && j==n){
				cout << tmp.idx;
				cx[i][j]=0;
				break;
			}
			int dx[2]={0,a[i][j]};
			int dy[2]={a[i][j],0};
			for(int k=0;k<2;k++){
				int r1=i+dx[k];
				int r2=j+dy[k];
				if(r1==m && r2==n){
					cout << tmp.idx+1;
					ok=true;
					cx[r1][r2]=0;
					break;
				}
				else if(r1<=m && r2<=n && cx[r1][r2]){
					q.push({r1,r2,tmp.idx+1});
					cx[r1][r2]=0;
				}
			}
			if(ok) break;
		}
		if(cx[m][n]) cout << -1 << endl;
		cout << endl;
	}
}