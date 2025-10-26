#include<bits/stdc++.h>
using namespace std;
set<int> se;
vector<int> v;
int n,k,a[1005]={0};
void inkq(){
	for(int i=1;i<=k;i++){
		cout << v[a[i]-1] << " ";
	}
	cout << endl;
}
void Try(int i){
	for(int j=a[i-1]+1;j<=v.size()-k+i;j++){
		a[i]=j;
		if(i==k){
			inkq();
		}
		else Try(i+1);
	}
}
int main() {
	cin >> n >>k;
	int x;
	for(int i=0; i<n; i++) {
		cin >> x;
		se.insert(x);
	}
	for(auto m : se){
		v.push_back(m);
	}
	Try(1);
}