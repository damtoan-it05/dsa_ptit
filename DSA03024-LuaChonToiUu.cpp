#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>> v;
		int x,y;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end(),cmp);
		int cnt=0,c=0;
		for(auto s:v){
			if(s.first>=c){
				cnt++;
				c=s.second;
			}
		}
		cout << cnt << endl;
	} 
}