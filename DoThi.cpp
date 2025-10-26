// danh sach ke
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int v,e;
	cin >> v >> e;
	vector<vector<int>> ds;
	for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		ds[u].push_back(v);
		ds[v].push_back(u);
	}
	for(int i=1;i<=v;i++){
		cout << "Danh sach ke cua dinh " << i << ": ";
		for(int x:ds[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}