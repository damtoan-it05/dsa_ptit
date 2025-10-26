#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin >> n;
	cin.ignore();
	int a[n+1][n+1];
	memset(a, 0, sizeof(a));
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while(ss>>tmp){
			int x=stoi(tmp);
			a[i][x]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    cout << a[i][j] << " ";
		}
		cout << endl;
	}
}