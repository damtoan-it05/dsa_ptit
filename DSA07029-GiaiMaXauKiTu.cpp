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
		for(char c:s) {
			if(c!=']') {
				st.push(c);
			} 
			else {
				string tmp="";
				while(!st.empty()&&st.top()!='[') {
					tmp=st.top()+tmp;
					st.pop();
				}
				st.pop();
				string x="";
				while(!st.empty()&&isdigit(st.top())) {
					x=st.top()+x;
					st.pop();
				}
				int cx;
				if(x=="") cx=1;
				else cx=stoi(x);
				string tmp1="";
				for(int i=0;i<cx;i++) {
					tmp1+=tmp;
				}
				for(int i=0;i<tmp1.size();i++){
					st.push(tmp1[i]);
				}
			}
		}
		string res="";
		while(!st.empty()){
			res = st.top()+res;
			st.pop();
		}
		cout << res << endl;
	}
}