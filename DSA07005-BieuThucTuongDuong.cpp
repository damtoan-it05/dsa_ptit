#include<iostream>
#include<stack>
using namespace std;
void Test() {
	string s;
	cin >> s;
	stack<char> st;
	for(char c:s) {
		if(c==')') {
			string tmp="";
			while(!st.empty()&&st.top()!='(') {
				tmp=st.top()+tmp;
				st.pop();
			}
			st.pop();
			bool ok=false;
			if(!st.empty()&&st.top()=='-') ok=true;
			for(int i=0; i<tmp.size(); i++) {
				if(tmp[i]=='+'&&ok) {
					st.push('-');
				} else if(tmp[i]=='-'&&ok) {
					st.push('+');
				} else st.push(tmp[i]);
			}
		} else {
			st.push(c);
		}
	}
	string res="";
	while(!st.empty()) {
		res=st.top()+res;
		st.pop();
	}
	cout << res << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		Test();
	}
}