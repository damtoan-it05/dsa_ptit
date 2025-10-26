#include<iostream>
#include<algorithm>
using namespace std;
int n,x[10], a[10];
void ktao(){
  for(int i=0;i<10;i++) a[i]=1;
}
void result(){
  for(int i=1;i<=n;i++)
	  cout << x[i];
	cout << endl;
}
void check(){
  for(int i=1;i<n;i++){
    if(abs(x[i]-x[i+1])<2) return;
  }
  result();
}
void Try(int i){
  for(int j=1;j<=n;j++){
    if(a[j]){
      x[i]=j;
      a[j]=0;
      if(i==n) check();
      else Try(i+1);
      a[j]=1;
    }
  }
}
void test(){
  cin >> n;
  Try(1);
}
int main(){
  int t;
  cin >> t;
  while(t--){
    ktao();
    test();
    cout << endl;
  }
}
