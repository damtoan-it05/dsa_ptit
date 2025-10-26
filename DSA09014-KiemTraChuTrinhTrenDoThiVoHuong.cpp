#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,cx[1005];
vector<int> vt[1005];
bool DFS(int s,int t){
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			if(DFS(c,s)){
				return true;
			}
		}
		else if(c!=t) return true;
	}
	return false;
}
void Test(){
	cin >> v >> e;
	for(int i=1;i<=v;i++){
		vt[i].clear();
	}
	memset(cx,1,sizeof(cx));
	for(int i=1;i<=e;i++){
		int x,y;
		cin >> x >> y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	for(int i=1;i<=v;i++){
		if(cx[i]){
			if(DFS(i,i)){
				cout << "YES";
				return;
			}
		}
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