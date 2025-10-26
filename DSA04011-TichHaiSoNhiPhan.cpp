#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll Solve(string s){
	ll res = 0, pow = 1;
	for(int i = s.size() - 1; i >= 0; i--){
		res += (s[i] - '0') * pow;
		pow *= 2;
	}
	return res;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	cout << Solve(s1) * Solve(s2) << endl;
	}
}