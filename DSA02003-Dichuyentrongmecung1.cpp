#include<iostream>
#include<vector>
using namespace std;
int n,a[20][20];
vector<string> v;
void result(){
	if(v.empty()){
		cout << "-1" << endl;
		return;
	}
	for(string x : v) cout << x << " ";
	cout << endl;
}
void Try(int i,int j, string s) {
  if(i==n-1&&j==n-1) {
		v.push_back(s);
		return;
	}
	if(i+1<n && a[i+1][j] ) {
		Try(i+1,j,s+'D');
	}
	if(j+1<n && a[i][j+1] ) {
		Try(i,j+1,s+'R');
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		v.clear();
		cin >> n;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cin >> a[i][j];
			}
		}
		if (a[0][0]) Try(0,0,"");
		result();
	}
}