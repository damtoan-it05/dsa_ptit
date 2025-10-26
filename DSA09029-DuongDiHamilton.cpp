#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int v,e,cx[20];
vector<int> vt[20];
bool ok=true;
void HMT(int s,int cnt){
	if(cnt==v){
		ok=false;
		return;
	}
	cx[s]=0;
	for(int c:vt[s]){
		if(cx[c]){
			HMT(c,cnt+1);
		}
	}
	cx[s]=1;
}
bool check(){
	ok=true;
	for(int i=1;i<=v;i++){
		if(cx[i]){
			HMT(i,1);
		}
	}
	return ok;
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
	check();
	if(!ok) cout << 1;
	else cout << 0;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
		cout << endl;
	}
}