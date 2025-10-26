#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
int n,k,m,a[105][105],idx=0;
map<pair<pair<int,int>,pair<int,int>>,int> mp;
map<pair<int,int>,int> dg;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
void DFS(int s,int t){
	if(a[s][t]==1){
		dg[{s,t}]=idx;
	}
	a[s][t]=-1;
	for(int k=0;k<4;k++){
		int x=s+dx[k];
		int y=t+dy[k];
		if(x>=1&&y>=1&&x<=n&&y<=n){
			if(a[x][y]!=-1 && !mp[{{s,t},{x,y}}]){
				DFS(x,y);
			}
		}
	}
}
void Test(){
	memset(a,0,sizeof(a));
	cin >> n >> k >> m;
	for(int i=1;i<=m;i++){
		int u,v,x,y;
		cin >> u >> v >> x >> y;
		mp[{{u,v},{x,y}}]=1;
		mp[{{x,y},{u,v}}]=1;
	}
	vector<pair<int,int>> vt;
	for(int i=1;i<=k;i++){
		int x,y;
		cin >> x >> y;
		a[x][y]=1;
		vt.push_back({x,y});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				idx++;
				DFS(i,j);
			}
		}
	}
	int res=0;
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(dg[{vt[i].first,vt[i].second}]!=dg[{vt[j].first,vt[j].second}]){
				res++;
			}
		}
	}
	cout << res << endl;
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
