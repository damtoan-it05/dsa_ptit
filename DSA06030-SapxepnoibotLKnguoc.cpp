#include<bits/stdc++.h>
using namespace std;
void in(vector<vector<int>> v,int n){
	for(int i=v.size()-1;i>=0;i--){
		cout << "Buoc " << i+1 << ": ";
		for(int j=0;j<n;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void Bubble(vector<vector<int>> &v,vector<int> &a,int n){
	for(int i=0;i<n;i++){
		int ok=1;
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				ok=0;
				swap(a[j],a[j+1]);
			}
		}
		if(ok) break;
		v.push_back(a);
	}
	in(v,n);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> v;
			for(auto &i :a) cin >> i;
		Bubble(v,a,n);
	}
}