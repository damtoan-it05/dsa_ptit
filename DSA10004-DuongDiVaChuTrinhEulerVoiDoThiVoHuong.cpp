#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int v,e;
		cin >> v >> e;
		int deg[v+1];
		memset(deg,0,sizeof(deg));
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			deg[x]++;deg[y]++;
		}
		int c=0,l=0;
		for(int i=1;i<=v;i++){
			if(deg[i]%2) l++;
			else c++;
		}
		if(l==2) cout << 1 << endl;
		else if(c==v) cout << 2 << endl;
		else cout << 0 << endl;
	}
}