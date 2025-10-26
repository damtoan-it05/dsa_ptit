#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		stack<long long> st;
		vector<string> s;
		string c,x;
		for(int i=0;i<n;i++){
			cin >> x;
			s.push_back(x);
		}
		for(int i=n-1;i>=0;i--){
			c=s[i];
			long long tmp;
			if(!st.empty()&&(c=="+"||c=="-"||c=="*"||c=="/")){
				tmp=st.top();
				st.pop();
				if(c=="+") tmp+=st.top();
				else if(c=="-") tmp-=st.top();
				else if(c=="*") tmp*=st.top();
				else if(c=="/") tmp/=st.top();
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