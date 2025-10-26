#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,res;
string s;
void Try(int u, int cnt){
	res=max(res,stoi(s));
  	if(cnt==n){
    	return;
  	}
  for(int i=u;i<s.size();i++){
    for(int j=i+1;j<s.size();j++){
      if(s[j] > s[i]){
        swap(s[i],s[j]);
        Try(u+1,cnt+1);
        swap(s[i],s[j]);
      }
    }
  }
}
int main(){
    int t;
    cin >> t;
    while(t--){
      cin >> n >> s;
      res=0;
      Try(0,0);
      cout << res << endl;
    }
}