#include<bits/stdc++.h>
using namespace std;
void Test(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  int x=2e6;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int s=a[i]+a[j];
      if(abs(s)<abs(x)) x=s;
    }
  }
  cout << x << endl;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    Test();
    cout << endl;
  }
}