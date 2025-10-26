#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[10][10],b[10][10];
vector<string> v;
void ktao(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> a[i][j];
      b[i][j]=1;
    }
  }
}
void Try(int i,int j,string s){
  if(i==n && j==n){
    v.push_back(s);
    return;
  }
  b[i][j]=0;
  if(i+1<=n && a[i+1][j] && b[i+1][j]) Try(i+1,j,s+'D');
  if(j+1<=n && a[i][j+1] && b[i][j+1]) Try(i,j+1,s+'R');
  if(i-1>=1 && a[i-1][j] && b[i-1][j]) Try(i-1,j,s+'U');
  if(j-1>=1 && a[i][j-1] && b[i][j-1]) Try(i,j-1,s+'L');
  b[i][j]=1;
}
void result(){
  if(v.empty()){
        cout << "-1" << endl; 
        return;
  }
  else{
    sort(v.begin(),v.end());
    for(string x : v){
         cout << x << " ";
    }
      cout << endl;
   }
}
int main(){
    int t;
    cin >> t;
    while(t--){
      v.clear();
      cin >> n;
      ktao();
      if(a[1][1]) Try(1,1,"");
      result();
    }
}