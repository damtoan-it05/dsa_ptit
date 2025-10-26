#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int v,e,pre[1005],sz[1005];
void Make_set() {
	for(int i=1; i<=v; i++) {
		pre[i]=i;
		sz[i]=1;
	}
}
int Find_set(int a) {
	if(a==pre[a]) return a;
	return pre[a]=Find_set(pre[a]);
}
bool Union(int a,int b) {
	a=Find_set(a);
	b=Find_set(b);
	if(a==b) return false;
	if(sz[a]<sz[b]) {
		swap(a,b);
	}
	sz[a]+=sz[b];
	pre[b]=a;
	return true;
}
void Test() {
	cin >> v >> e;
	Make_set();
	bool check=true;
	for(int i = 1; i <=e; i++) {
		int x, y;
		cin >> x >> y;
		if(Union(x, y)) {
			continue;
		} else {
			check = false;
		}
	}
	if(!check) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		Test();
	}
}