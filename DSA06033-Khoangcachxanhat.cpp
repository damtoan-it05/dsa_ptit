#include<bits/stdc++.h>
using namespace std;
void Test(){
  int n;
  cin >> n;
  pair<int,int> a[n];
  for(int i=0;i<n;i++){
    cin >> a[i].first;
    a[i].second=i;
  }
  sort(a,a+n);
  int d=-1,m1=a[0].first,m2=a[0].second;
  for(int i=1;i<n;i++){
    if(a[i].first > m1){
      d=max(d,a[i].second-m2);
    }
    if(m2>a[i].second){
      m1=a[i].first;
      m2=a[i].second;
    }
  }
  cout << d << endl;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    Test();
    cout << endl;
  }
}