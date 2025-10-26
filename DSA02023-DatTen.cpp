#include<iostream>
#include<set>
#include<vector>
using namespace std;
int n,k,x[50];
vector<string> v;
void result(){
	for(int i=1;i<=k;i++){
		cout << v[x[i]-1] << " ";
	}
	cout << endl;
}
void Try(int i){
	for(int j=x[i-1]+1;j<=n-k+i;j++){
		x[i]=j;
		if(i==k) result();
		else Try(i+1);
	}
}
int main(){
	int t;
	t=1;
	while(t--){
		cin >> n >> k;
		string s;
		set<string> se;
		for(int i=0;i<n;i++){
			cin >> s;
			se.insert(s);
		}
		n=se.size();
		for(auto x : se){
			v.push_back(x);
		}
		x[0]=0;
		Try(1);
		v.clear();
	} 
}