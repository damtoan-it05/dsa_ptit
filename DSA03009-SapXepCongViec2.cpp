#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int> x1, pair<int,int> x2){
	if(x1.second == x2.second){
		return x1.first>x2.first;
	}
	else return x1.second > x2.second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int x,y,z,deadline=0;
		vector<pair<int,int>> v;
		vector<int> a(1005,0);
		for(int i=0;i<n;i++){
			cin >> x >> y >> z;
			v.push_back({y,z});
		}
		sort(v.begin(),v.end(),cmp);
		long long res=0,cnt=0;
		for(int i=0;i<n;i++){
			for(int j=v[i].first;j>=1;j--){
			  if(!a[j]){
			    a[j]=1;
			    cnt++;res+=v[i].second;
			    break;
			  }
			}
		}
		cout << cnt << " " << res << endl;
	} 
}