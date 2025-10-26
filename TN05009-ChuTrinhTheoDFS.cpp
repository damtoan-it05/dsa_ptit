#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
int v,e,c[1005],pre[1005],res;
set<int> vt[1005];
bool DFS(int s) {
	c[s]=0;
	for(int i:vt[s]) {
		if(c[i]) {
			pre[i]=s;
			if(DFS(i))return true;
		} else if(i!=pre[s]&&i==1) {
			res=s;
			return true;
		}
	}
	return false;
}
void Test() {
	cin >> v >> e;
	for(int i=1; i<=v; i++) {
		vt[i].clear();
	}
	memset(c,1,sizeof(c));
	memset(pre,0,sizeof(pre));
	for(int i=1; i<=e; i++) {
		int x,y;
		cin >> x >> y;
		vt[x].insert(y);
		vt[y].insert(x);
	}
	if(DFS(1)) {
		vector<int> r;
		r.push_back(1);
		while (res != 1) {
			r.push_back(res);
			res = pre[res];
		}
		r.push_back(1);
		for(int j=r.size()-1; j>=0; j--) {
			cout << r[j] << " ";
		}
	} 
	else cout << "NO";
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		Test();
		cout << endl;
	}
}