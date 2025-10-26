#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void DFS(vector<vector<int>> &v,int i, int j, int n, int m){
	v[i][j]=0;
	for(int k=0;k<4;k++){
		int ni=i+dx[k],nj=j+dy[k];
		if(ni>=0 && ni<n &&nj>=0 && nj<m && v[ni][nj]==1){
			DFS(v,ni,nj,n,m);
		}
	}
}
int main() {
	int n,m;
	cin >> n >> m;
	char tmp;
	vector<vector<int>> a(n,vector<int> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> tmp;
			if(tmp=='.') a[i][j]=0;
			else if(tmp=='#') a[i][j]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]){
				cnt++;
				DFS(a,i,j,n,m);
			}
		}
	}
	cout << cnt;
	return 0;
}