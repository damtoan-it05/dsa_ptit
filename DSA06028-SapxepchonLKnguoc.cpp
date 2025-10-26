#include<bits/stdc++.h>
using namespace std;
void in(vector<vector<int>> v,int n){
	for(int i=n-2;i>=0;i--){
		cout << "Buoc " << i+1 << ": ";
		for(int j=0;j<n;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void Selection(vector<vector<int>> &v,vector<int> &a, int n){
	for(int i=0;i<n;i++){
		int tmp=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[tmp]){
				tmp=j;
			}
		}
		swap(a[i],a[tmp]);
		v.push_back(a);
	}
	in(v,n);
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> v;
	for(auto &i : a) cin >> i;
	Selection(v,a,n);
}