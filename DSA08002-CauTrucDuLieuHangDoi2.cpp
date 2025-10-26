#include<iostream>
#include<queue>
using namespace std;
int main() {
	int t;
	t=1;
	while(t--) {
		int n;
		cin >> n;
		queue<int> q;
		while(n--) {
			string s;
			cin >> s;
			if(s== "PUSH") {
				int tmp;
				cin >> tmp;
				q.push(tmp);
			}

			else if(s== "POP") {
				if(!q.empty()) q.pop();
			}

			else if(s== "PRINTFRONT") {
				if(!q.empty()) {
					cout << q.front();
				} else cout << "NONE";
				cout << endl;
			}

		}
	}
}