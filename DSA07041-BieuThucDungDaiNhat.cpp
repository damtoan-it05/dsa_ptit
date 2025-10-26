#include<iostream>
#include<stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		stack<char> st;
		int cnt=0;
		for(char c:s) {
			if(c==')') {
				if(!st.empty()&&st.top()=='('){
					cnt+=2;
					st.pop();
				}
			} 
			else {
				st.push(c);
			}
		}
		cout << cnt << endl;
	}
}