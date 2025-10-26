#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,cx[1005];
vector<int> vt[1005];
vector<pair<int,int>> v;
void DFS(int s){
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			v.push_back({s,c});
			DFS(c);
		}
	}
}
void Test(){
	cin >> n;
	for(int i=1;i<=n;i++){
		vt[i].clear();
	}
	v.clear();
	memset(cx,1,sizeof(cx));
	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
	}
	DFS(1);
	if(v.size()==n-1){
		cout << "YES";
		return;
	}
	cout << "NO";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}