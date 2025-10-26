#include<bits/stdc++.h>
using namespace std;
void Test(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
	  cin >> a[i];
	}
	int l[n]={},r[n+1]={};
	vector<int> v;
	l[0]=a[0];
	for(int i=1;i<n;i++){
	  l[i]=max(a[i],l[i-1]);
	}
	r[n]=a[n-1];
	for(int i=n-1;i>=0;i--){
	  r[i]=min(a[i],r[i+1]);
	}
	for(int i=0;i<n-1;i++){
	  if(l[i]<=r[i+1]){
	    v.push_back(i+1);
	  }
	}
	cout << v.size() << endl;
	for(auto x : v ){
	    cout << x << " ";
	  }
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Test();
		cout << endl;
	}
}