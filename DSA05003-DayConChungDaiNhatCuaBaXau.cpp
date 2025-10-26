#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		string s1,s2,s3;
		cin >> s1 >> s2 >> s3;
		int dp[n+1][m+1][k+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int h=1;h<=k;h++){
					if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[h-1]){
						dp[i][j][h]=dp[i-1][j-1][h-1]+1;
					}
					else dp[i][j][h]=max(dp[i-1][j][h],max(dp[i][j-1][h],dp[i][j][h-1]));
				}
			}
		}
		cout << dp[n][m][k] << endl;
	}
}