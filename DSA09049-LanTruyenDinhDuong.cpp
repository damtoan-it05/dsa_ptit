#include<iostream>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
const int M=2e5+5;
int n;
vector<int>Ke[M];
long long sz[M],val[M];
void DFS(int s){
	val[s]=1;
	sz[s]=0;
	for(int i:Ke[s]){
		DFS(i);
		sz[s]+=sz[i]+1;
		val[s]+=val[i];
	}
	val[s]+=sz[s];
}
void Test(){
	cin >> n;
	for(int i=2;i<=n;i++){
		int tmp;
		cin >> tmp;
		Ke[tmp].push_back(i);
	}
	DFS(1);
	for(int i=1;i<=n;i++){
		cout << val[i] << " ";
	}
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
