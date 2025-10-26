#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[25],x[25];
vector<vector<int>> v;
bool cmp(vector<int> a,vector<int> b){
  string c="",d="";
  for(auto i : a) c+=to_string(i)+" ";
  for(auto i : b) d+=to_string(i)+" ";
  return c < d;
}
void result(){
	for(auto h : v){
	  for(int i=0;i<h.size();i++){
		  cout << h[i];
		  if(i!=h.size()-1) cout << " ";
	  }
	  cout << endl;
	}
}
void check(){
  int tmp=0;
  vector<int> v1;
	for(int i=1;i<=n;i++){
	  if(x[i]){
	    if(a[i]<tmp) return;
	    else tmp=a[i];
	    v1.push_back(a[i]);
	  }
	}
	if(v1.size()<2) return;
	v.push_back(v1);
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			check();
		}
		else Try(i+1);
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	Try(1);
	sort(v.begin(),v.end(),cmp);
	result();
}