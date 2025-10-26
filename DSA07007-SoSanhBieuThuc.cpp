#include<iostream>
#include<stack>
using namespace std;
string Test(string s) {
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
	return res;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s1,s2;
		cin >> s1 >> s2;
		s1=Test(s1);
		s2=Test(s2);
		if(s1!=s2) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}