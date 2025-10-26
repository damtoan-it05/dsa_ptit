#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char>st;
		int cnt=0;
		for(char c:s){
			if(st.empty()){
				st.push(c);
				continue;
			}
			if(c==')'&&st.top()=='('){
				cnt+=2;
				st.pop();	
			}
			else if(c==']'&&st.top()=='['){
				cnt+=2;
				st.pop();	
			}
			else if(c=='}'&&st.top()=='{'){
				cnt+=2;
				st.pop();	
			}
			else st.push(c);
		}
		if(cnt==s.size()){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
}