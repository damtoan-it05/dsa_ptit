#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		string s;
		cin >> s;
		cout << x << " ";
		if(next_permutation(s.begin(),s.end())){
			cout << s << endl;
		}
		else{
			cout << "BIGGEST" << endl;
		}
	}
}