#include <iostream>
using namespace std;
void test(){
  int n;
  cin >> n;
  int s=0,x;
  for(int i=0;i<n;i++){
    cin >> x;
    s+=x;
  }
  if(s%2==0) cout << "YES";
  else cout << "NO";
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        test();
        cout << endl;
    }
    return 0;
}