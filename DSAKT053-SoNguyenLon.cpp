#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string x,y;
		cin >> x >> y;
		int n=x.size(),m=y.size();
		int d[n+1][m+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(j==0||i==0) d[i][j]=0;
				else if(x[i-1]==y[j-1]){
					d[i][j]=d[i-1][j-1]+1;
				}
				else d[i][j]=max(d[i-1][j],d[i][j-1]);
			}
		}
		cout << d[n][m] << endl;
	}
}