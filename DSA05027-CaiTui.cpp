#include<iostream>
#include<cstring>
using namespace std;
int n,v,a[1005],c[1005];
void ktao(){
	cin >> n >> v;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
}
void dynamic(){
	// xay dung bang phuong an: luu kq tong gia tri lon nhat cua i do vat
	int dp[n+1][v+1];
	//ktao gia tri ban dau cho bang phuong an
	memset(dp,0,sizeof(dp));
	//  truy vet bai toan con truoc do -> tong gia tri lon nhat cua n do vat voi the tich <=V
	for(int i=1;i<=n;i++){
		for(int j=0;j<=v;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+c[i]);
			}
		}
	}
	cout << dp[n][v] << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		ktao();
		dynamic();
	}
}