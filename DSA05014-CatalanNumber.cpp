#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 101;

string Cong_Xau(string a, string b){
    int len = max(a.size(), b.size());
    while(a.size() < len) a = "0" + a;
    while(b.size() < len) b = "0" + b;
    string res = "";
    int carry = 0;
    for(int i = (len - 1); i >= 0; i--){
        int x = (a[i] - '0') + (b[i] - '0') + carry;
        res = to_string(x % 10) + res;
        carry = x / 10;
    }
    if(carry){
        res = to_string(carry) + res;
    }
    return res;
}

string Nhan_Xau(string a, string b){
    string res = string(a.size() + b.size() + 1, '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        int carry = 0;
        for(int j = 0; j < b.size(); j++){
            int x = (a[i] - '0') * (b[j]  -'0') + (res[i + j] - '0') + carry;
            res[i + j] = ((x % 10) + '0');
            carry = x / 10;
        }
        if(carry){
            res[i + b.size()] = (carry + '0');
        }
    }
    reverse(res.begin(), res.end());
    while((res.size() > 1) and (res[0] == '0')){
        res.erase(0, 1);
    }
    return res;
}

string C[maxn];

void Catalan_Number(){
    C[0] = C[1] = "1";
    for(int n = 2; n <= 100; n++){
        C[n] = "0";
        for(int i = 0; i < n; i++){
            C[n] = Cong_Xau(C[n], Nhan_Xau(C[i], C[n-i-1]));
        }
    }
}

int main(){
    Catalan_Number();
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        cout << C[n] << endl;
    }
}