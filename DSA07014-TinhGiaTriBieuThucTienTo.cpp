#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<int> st;
		for(int i=s.size()-1;i>=0;i--){
			char c=s[i];
			int tmp;
			if(c=='+'){
				tmp=st.top();
				st.pop();
				tmp+=st.top();
				st.pop();
			}
			else if(c=='-'){
				tmp=st.top();
				st.pop();
				tmp-=st.top();
				st.pop();
			}
			else if(c=='*'){
				tmp=st.top();
				st.pop();
				tmp*=st.top();
				st.pop();
			}
			else if(c=='/'){
				tmp=st.top();
				st.pop();
				tmp/=st.top();
				st.pop();
			}
			else{
				tmp=c-'0';
			}
			st.push(tmp);
		}
		cout << st.top() << endl;
	}
}