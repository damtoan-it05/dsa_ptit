#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int cx[1005],pre[1005];
vector<int> vt[1005];
void DFS(int s){
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			pre[c]=s;
			DFS(c);
		}
	}
}
void Path(int s,int t){
	vector<int> v;
	if(pre[t]==-1){
		cout << -1 << endl;
		return;
	}
	else{
		v.push_back(t);
		int x=pre[t];
		while(x!=s){
			v.push_back(x);
			x=pre[x];
		}
		v.push_back(s);
	}
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i] << " ";
	}
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int v,e,s,t;
		cin >> v >> e >> s >> t;
		for (int i = 1; i <= v; i++){
			vt[i].clear();
		}
		memset(cx,1,sizeof(cx));
		memset(pre,-1,sizeof(pre));
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			vt[x].push_back(y);
		}
		DFS(s);
		Path(s,t);
	}
}