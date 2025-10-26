#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,c[1005];
vector<int> vt[1005];
bool DFS(int s,int pre){
	c[s]=1-c[pre];
	for(int i:vt[s]){
		if(c[i]==-1){
			if(!DFS(i,s)){
				return false;
			}
		}
		else if(c[i]==c[s]) return false;
	}
	return true;
}
void Test(){
	cin >> v >> e;
	for(int i=1;i<=v;i++){
		vt[i].clear();
	}
	memset(c,-1,sizeof(c));
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	bool ok=true;
	c[0]=1;
	for(int i=1;i<=v;i++){
		if(c[i]==-1){
			if(!DFS(i,0)){
				ok=false;
				break;
			}
		}
	}
	if(ok) cout << "YES";
	else cout << "NO";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}