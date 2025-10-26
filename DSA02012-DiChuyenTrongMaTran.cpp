#include<iostream>
using namespace std;
int n, m, cnt;
void Try(int i, int j){
	if(i==n-1&&j==m-1){
		cnt++;
	}
	if(i+1<n) Try(i+1,j);
	if(j+1<m) Try(i,j+1);
}
int main(){
	int t;
	cin >> t;
	while(t--){
	  cnt=0;
		cin >> n >> m;
		int a[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> a[i][j];
			}
		}
		Try(0,0);
		cout << cnt << endl;
	}
}