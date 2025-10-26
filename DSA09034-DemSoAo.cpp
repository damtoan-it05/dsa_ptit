#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
int n,m,a[105][105];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void DFS(int s,int t){
	a[s][t]=0;
	for(int k=0;k<8;k++){
		int x=s+dx[k];
		int y=t+dy[k];
		if(x>=1&&y>=1&&x<=n&&y<=m&&a[x][y]){
			DFS(x,y);
		}
	}
}
void Test(){
	memset(a,0,sizeof(a));
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin >> c;
			if(c=='W') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	int idx=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				idx++;
				DFS(i,j);
			}
		}
	}
	cout << idx << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	t=1;
	while(t--){
		Test();
	}
}
