#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

string Solve(string s1, string s2, int k){
	int len = max(s1.size(), s2.size());
	while(s1.size() < len) s1 = "0" + s1;
	while(s2.size() < len) s2 = "0" + s2;
	string res = "";
	int carry = 0;
	for(int i = len - 1; i >= 0; i--){
		int x = (s1[i] - '0') + (s2[i] - '0') + carry;
		res = to_string(x % k) + res;
		carry = x / k;
	}
	if(carry){
		res = to_string(carry) + res;
	}
	return res;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
    	int k;
    	string s1, s2;
    	cin >> k >> s1 >> s2;
    	cout << Solve(s1, s2, k) << endl;
	}
}