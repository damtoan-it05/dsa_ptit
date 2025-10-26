#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int Priority(char c) {
	if(c=='+'||c=='-') return 1;
	if(c=='*'||c=='/') return 2;
	return 0;
}
long long Math(long long x,char c, long long y) {
	if(c=='+') return x+y;
	else if(c=='-') {
		return x-y;
	} else if(c=='*') {
		return x*y;
	} else if(c=='/') {
		return x/y;
	}
	return 0;
}
void Ans(string s) {
	stack<long long> st;
	stack<char> vt;
	int i=0;
	while(i<s.size()) {
		if(isdigit(s[i])) {
			int val=0;
			while(i<s.size()&& isdigit(s[i])) { 
				val=val*10+(s[i]-'0');
				i++;
			}
			st.push(val); 
		} else if(s[i]=='(') {
			vt.push(s[i]);
			i++;
		} else if(s[i]==')') {
			while(!vt.empty()&&vt.top()!='(') {
				long long b=st.top(); st.pop();
				long long a=st.top(); st.pop();
				char x=vt.top(); vt.pop();
				st.push(Math(a,x,b));
			}
			vt.pop();
			i++;
		} 
		else {
			while(!vt.empty()&&Priority(vt.top())>=Priority(s[i])) {
				long long b=st.top(); st.pop();
				long long a=st.top(); st.pop();
				char x=vt.top(); vt.pop();
				st.push(Math(a,x,b));
			}
			vt.push(s[i]);
			i++;
		}
	}
	while(!vt.empty()) {
		long long b=st.top(); st.pop();
		long long a=st.top(); st.pop();
		char x=vt.top(); vt.pop();
		st.push(Math(a,x,b));
	}
	cout << st.top() << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		Ans(s);
	}
}