#include<bits/stdc++.h>
using namespace std;
void in(vector<vector<int>> v,int n){
	for(int i=n-1;i>=0;i--){
		cout << "Buoc " << i << ": ";
		for(int j=0;j<=i;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
void Insert(vector<vector<int>> &v,vector<int> &a,int n){
	v.push_back(a);
	for(int i=1;i<n;i++){
		int tmp=a[i];
		int j=i-1;
		while(j>=0&&a[j]>tmp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=tmp;
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
	Insert(v,a,n);
}