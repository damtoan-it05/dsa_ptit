#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	string s;
	stack<int> st;
	while(cin >> s){
		if(s=="push"){
			int n;
			cin >> n;
			st.push(n);
		}
		else if(s=="pop"){
			st.pop();
		}
		else if(s=="show"){
			vector<int> v;
			if(st.empty()){
				cout << "empty" << endl;
			}
			while(!st.empty()){
				int tmp=st.top();
				st.pop();
				v.push_back(tmp);
			}
			for(int i=v.size()-1;i>=0;i--){
				cout << v[i] << " ";
				st.push(v[i]);
			}
			cout << endl;
		}
	}
}