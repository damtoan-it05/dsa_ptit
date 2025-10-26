#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<int> v;
		int a[n], b[m], c[k];
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<m;i++) cin >> b[i];
		for(int i=0;i<k;i++) cin >> c[i];
		int x=0,y=0,z=0;
		while(x<n && y<m && z<k){
			if(a[x]==b[y] && b[y]==c[z]){
				v.push_back(a[x]);
				x++;y++;z++;
			}
			else if(a[x] < b[y]) x++;
			else if(b[y] < c[z]) y++;
			else z++;
		}
		for(int s:v){
			cout << s << " ";
		}
		if(v.empty()) cout << "NO";
		cout << endl;
	} 
}