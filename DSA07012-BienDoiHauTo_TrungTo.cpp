#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<string> st;
		string tmp;
		for(char c:s){
			tmp="";
			if(c=='+'||c=='-'||c=='*'||c=='/'){
				tmp=st.top();
				st.pop();
				tmp="("+st.top()+c+tmp+")";
				st.pop();
			}
			else{
				tmp+=c;
			}
			st.push(tmp);
		}
		cout << st.top() << endl;
	}
	return 0;
}