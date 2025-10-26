#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		vector<bool> dp(k+1,false);
		dp[0]=true;
		for(int i=0;i<n;i++){
			for(int j=k;j>=a[i];j--){
				if(dp[j-a[i]]){
					dp[j]=true;
				}
			}
		}
		if(dp[k]) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}