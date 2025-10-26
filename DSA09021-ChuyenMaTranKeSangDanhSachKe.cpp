#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n+1][n+1];
	vector<int> v[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    cin >> a[i][j];
		    if(a[i][j]) v[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int c:v[i]){
			cout << c << " ";
		}
		cout << endl;
	}
	return 0;
}