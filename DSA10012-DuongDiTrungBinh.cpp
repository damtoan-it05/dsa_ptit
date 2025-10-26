#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;

int n,m,d[105][105];
const int Inf = 1e9;

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) d[i][j]=0;
			else d[i][j]=Inf;
		}
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

void Test(){
	cin >> n >> m;
	init();
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		d[x][y]=1;
	}
	Floyd();
	int cnt=0;
	double s=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]!=0&&d[i][j]!=Inf){
				s+=d[i][j];
				cnt++;
			}
		}
	}
	s=s/cnt;
	cout << fixed << setprecision(2) << s << endl;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}