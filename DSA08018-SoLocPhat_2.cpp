#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
void NP(int n) {
	queue<string> q;
	q.push("6");
	q.push("8");
	v.push_back("6");
	v.push_back("8");
	while(1) {
		string tmp=q.front();
		if(tmp.size()==n){
			return;
		}
		q.pop();
		q.push(tmp+"6");v.push_back(tmp+"6");
		q.push(tmp+"8");v.push_back(tmp+"8");
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		NP(n);
		cout << v.size() << endl;
		for(string s:v){
			cout << s << " ";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}