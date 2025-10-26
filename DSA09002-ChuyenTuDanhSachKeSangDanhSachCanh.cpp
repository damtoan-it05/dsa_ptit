#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	vector<pair<int,int>> vt;
	for(int i=1; i<=n; i++) {
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			int x=stoi(tmp);
			if(i < x) vt.push_back({i,x});
		}
	}
	for(pair<int,int> c:vt) {
		cout << c.first << " " << c.second << endl;
	}
}