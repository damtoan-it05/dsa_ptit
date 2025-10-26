#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m,a[505][505],d[505][505],cx[505][505];
const int INF=1e9;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void Dijkstra(int i,int j){
	d[i][j]=a[i][j];
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	q.push({a[i][j],{i,j}});
	while(!q.empty()){
		pair<int,pair<int,int>> p=q.top();q.pop();
		int u=p.second.first,v=p.second.second;
		if(cx[u][v]==0) continue;
		cx[u][v]=0;
		for(int k=0;k<4;k++){
			int x=u+dx[k];
			int y=v+dy[k];
			if(x>=1&&x<=n&&y>=1&&y<=m){
				d[x][y]=min(d[x][y],d[u][v]+a[x][y]);
				q.push({d[x][y],{x,y}});
			}
		}
	}
	cout << d[n][m] << endl;
}

void Test(){
	cin >> n >> m;
	memset(cx,1,sizeof(cx));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			d[i][j]=INF;
		}
	}
	Dijkstra(1,1);
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}