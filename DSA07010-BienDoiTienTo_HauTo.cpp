#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		for(int i=s.size()-1;i>=0;i--){
			char c=s[i];
			string tmp="";
			if(c=='-'||c=='+'||c=='*'||c=='/'){
				tmp+=st.top();
				st.pop();
				tmp+=st.top()+c;
				st.pop();
				st.push(tmp);
			}
			else {
				tmp+=c;
				st.push(tmp);
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}