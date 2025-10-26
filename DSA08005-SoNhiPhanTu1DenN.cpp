#include<iostream>
#include<queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		queue<string> q;
		q.push("1");
		int cnt=0;
		while(cnt<n) {
			string tmp=q.front();
			cout << tmp << " ";
			cnt++;
			q.push(tmp+"0");
			q.push(tmp+"1");
			q.pop();
		}
		cout << endl;
	}
}