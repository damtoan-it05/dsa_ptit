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
		int vao[v+1],ra[v+1];
		memset(vao,0,sizeof(vao));
		memset(ra,0,sizeof(ra));
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			ra[x]++;vao[y]++;
		}
		int c=0;
		for(int i=1;i<=v;i++){
			if(ra[i]==vao[i]) c++;
		}
		if(c==v) cout << 1 << endl;
		else cout << 0 << endl;
	}
}