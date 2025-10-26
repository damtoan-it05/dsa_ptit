#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		stack<long long> st;
		string c;
		for(int i=0;i<n;i++){
			cin >> c;
			long long tmp;
			if(!st.empty()&&(c=="+"||c=="-"||c=="*"||c=="/")){
				tmp=st.top();
				st.pop();
				if(c=="+") tmp=st.top()+tmp;
				else if(c=="-") tmp=st.top()-tmp;
				else if(c=="*") tmp=st.top()*tmp;
				else if(c=="/") tmp=st.top()/tmp;
				st.pop();
			}
			else{
				tmp=stoll(c);
			}
			st.push(tmp);
		}
		cout << st.top() << endl;
	}
	return 0;
}