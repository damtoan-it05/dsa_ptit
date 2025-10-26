#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

/*
- Ý tưởng: Phân tích a/b = 1/x + c/d
+ Với x = Ceil(b/a), (c/d) = (a/b) - (1/x)
+ Phân tích đến khi (d % c == 0) thì (c/d) sẽ là phân số đơn vị
*/

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        ll a, b;
        cin >> a >> b;
        while(1){
            if((b % a) == 0){
                b /= a; a /= a;
                cout << a << "/" << b << endl;
                break;
            }
            ll x = b/a + 1;
            cout << "1/" << x << " + ";
            a = a * x - b;
            b = b * x;
        }
    }
}