#include<bits/stdc++.h>
using namespace std;
void Test(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &x:v) cin >> x;
  int s=1,l[100005]={}, r[100005]={};
  l[0]=1;
  for(int i=1;i<n;i++){
    if( v[i] > v[i-1]){
    	l[i]=l[i-1]+1;
	  }
	  else l[i]=1;
  }
  r[n-1]=1;
  for(int i=n-2;i>=0;i--){
    if( v[i] > v[i+1]){
    	r[i]=r[i+1]+1;
	  }
	  else r[i]=1;
  }
  for(int j=0;j<n;j++){
  	s=max(s,l[j]+r[j]-1);
  }
  cout << s;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    Test();
    cout << endl;
  }
}