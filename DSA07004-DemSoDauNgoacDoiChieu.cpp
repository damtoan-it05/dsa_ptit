#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		stack<int> st;
		int cnt=0,n=s.size()/2;
		for(char c : s){
			if(c==')'){
				if(st.empty()){
					st.push('(');
					cnt--;
				}
				else if(st.top()=='('){
					cnt++;
					st.pop();
				}
			}
			else st.push(c);
		}
		cout << n-cnt << endl;
	}
}