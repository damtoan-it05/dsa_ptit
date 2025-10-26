#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
// duyet tat ca nguoi de tim gia tri cua moi dinh(so nguoi co the den dinh do) neu gia tri = k thi co the hop mat tai do
int n,m,k,cx[1005],hop[1005];
vector<int> vt,Ke[1005];
void DFS(int s){
	cx[s]=0;
	hop[s]++;
	for(int i:Ke[s]){
		if(cx[i]){
			DFS(i);
		}
	}
}
void Test(){
	memset(hop,0,sizeof(hop));
	cin >> k >> n >> m;
	for(int i=1;i<=k;i++){
		int tmp;
		cin >> tmp;
		vt.push_back(tmp);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		Ke[x].push_back(y);
	}
	for(int x:vt){
		memset(cx,1,sizeof(cx));
		DFS(x);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(hop[i]==k) res++;
	}
	cout << res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	t=1;
	while(t--){
		Test();
	}
}
