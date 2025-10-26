#include<iostream>
#include<vector>
using namespace std;

const int INF=1e9;
int n,m;
int d[105][105];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=INF;
		}
	}
}

void input(){
	cin >> n >> m;
	init();
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		d[x][y]=d[y][x]=z;
	}
}

void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}

int main(){
	input();
	Floyd();
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		cout << d[x][y] << endl;
	}
}