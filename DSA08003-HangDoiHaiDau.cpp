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
			if(s== "PUSHBACK") {
				int tmp;
				cin >> tmp;
				q.push(tmp);
			}
			else if(s== "PUSHFRONT") {
				int tmp;
				cin >> tmp;
				int c=q.size();
				q.push(tmp);
				while(c--){
					q.push(q.front());
					q.pop();
				}	
			}
			else if(s== "POPBACK") {
				if(!q.empty()){
					int c=q.size()-1;
					while(c--){
						q.push(q.front());
						q.pop();
					}
					q.pop();
				}
			}
			else if(s== "POPFRONT") {
				if(!q.empty()) q.pop();
			}
			else if(s== "PRINTFRONT") {
				if(!q.empty()) {
					cout << q.front();
				} else cout << "NONE";
				cout << endl;
			}
			else if(s== "PRINTBACK") {
				if(!q.empty()) {
					cout << q.back();
				} else cout << "NONE";
				cout << endl;
			}
		}
	}
}