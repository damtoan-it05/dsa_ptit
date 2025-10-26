#include<iostream>
#include<stack>
using namespace std;
void Test() {
	string s;
	cin >> s;
	stack<char> st;
	string res="";
	for(char c:s) {
		if(c!='<'&&c!='>'&&c!='-') {
			res+=c;
		} 
		else if(c=='<') {
			if(!res.empty()){
				st.push(res.back());
				res.pop_back();
			}
		}
		else if(c=='>') {
			if(!st.empty()){
				res+=st.top();
				st.pop();
			}
		}
		else if(c=='-') {
			if(!res.empty()) res.pop_back();
		}
	}
	while(!st.empty()) {
		res+=st.top();
		st.pop();
	}
	cout << res;
}
int main() {
	int t;
	t=1;
	while(t--) {
		Test();
	}
}