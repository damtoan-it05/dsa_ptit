#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,m,a[15];
vector<int> vt[15];
bool ok=true;
bool check(int i,int j){
	for(int c:vt[i]){
		if(a[c]==j) return false;
	}
	return true;
}
void Try(int i){
	if(!ok) return;
	for(int j=1;j<=m;j++){
		if(check(i,j)){
			a[i]=j;
			if(i==v){
				cout << "YES";
				ok=false;
				return;
			}
			else Try(i+1);
			a[i]=0;
		}
	}
}
void Test(){
	cin >> v >> e >> m;
	for(int i=1;i<=v;i++){
		vt[i].clear();
	}
	ok=true;
	memset(a,0,sizeof(a));
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	Try(1);
	if(ok) cout << "NO";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}