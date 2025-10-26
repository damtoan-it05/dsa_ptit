#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct Data {
	int x,y,w;
};
int v,e;
vector<Data> vt;
const int Inf=1e9;

bool Bellman_Ford(int u) {
	vector<int> d(v+1,Inf);
	d[u]=0;
	for(int i=1; i<=v; i++) {
		for(auto c:vt) {
			int x=c.x,y=c.y;
			if(d[x] <Inf) {
				d[y]=min(d[y],d[x]+c.w);
			}
		}
	}
	for(auto c:vt) {
		int x=c.x,y=c.y;
		if(d[x] <Inf) {
			if(d[y]>d[x]+c.w){
				return true;
			}
		}
	}
	return false;
}

void Test() {
	cin >> v >> e;
	vt.clear();
	for(int i=1; i<=e; i++) {
		int x,y,w;
		cin >> x >> y >> w;
		vt.push_back({x,y,w});
	}
	bool ok=false;
	for(int i=1; i<=v; i++) {
		if(Bellman_Ford(i)) {
			ok=true;
			break;
		}
	}
	if(ok) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Test();
	}
}