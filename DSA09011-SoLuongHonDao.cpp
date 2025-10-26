#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int m,n,a[505][505];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void DFS(int i,int j){
	a[i][j]=0;
	for(int k=0;k<8;k++){
		int x=i+dx[k];
		int y=j+dy[k];
		if(x>=1&&x<=n && y>=1&&y<=m &&a[x][y]){
			DFS(x,y);
		}
	}
}
void Test(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				DFS(i,j);
				++cnt;
			}
		}
	}
	cout << cnt;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}