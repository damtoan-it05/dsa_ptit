#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	cin.ignore();
	string s;
	while(t--){
		getline(cin,s);
		stack<int> st;
		bool ok;
		for(char c:s){
			if(c==')'){
				ok=true;
				while(st.top()!='('){
					int tmp=st.top();
					if(tmp=='+'||tmp=='-'||tmp=='*'||tmp=='/') ok =false;
					st.pop();
				}
				if(ok){
					cout << "Yes" << endl;
					break;
				}
				st.pop();
			}
			else st.push(c);
		}
		if(!ok) cout << "No" <<endl;
	}
}