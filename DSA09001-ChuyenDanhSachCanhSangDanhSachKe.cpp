#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int v,e;
		cin >> v >> e;
		vector<int> vt[v+1];
		for(int i=0;i<e;i++){
			int x,y;
			cin >> x >> y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		for(int i=1;i<=v;i++){
			cout << i << ": ";
			for(int s:vt[i]){
				cout << s << " ";
			}
			cout << endl;
		}
	}
}