#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int n;
int Priority(char c){
	if(c=='+'|| c=='-') return 1;
	if(c=='*'|| c=='/') return 2;
	if(c=='^') return 3;
	return 0;
}
void TrungTo_HauTo(string a) {
	stack<char> s;
	string res="";
	for(int i=0; i<n; i++) {
		if(a[i]=='(') s.push(a[i]);
		else if(isalnum(a[i])) res+=a[i];
		else if(a[i]==')') {
			while(!s.empty() && s.top()!='(') {
				char c=s.top();
				s.pop();
				res+=c;
			}
			s.pop();
		} else {
			while(!s.empty() && Priority(a[i])<=Priority(s.top())) {
				char c=s.top();
				s.pop();
				res+=c;
			}
			s.push(a[i]);
		}
	}
	while(!s.empty()){
		char c=s.top();
		if(c!='(') res+=c;
		s.pop();
	}
	cout << res << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		n=a.size();
		TrungTo_HauTo(a);
	}
}