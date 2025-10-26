#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin >> a[i];
		stack<int> st;
		int i=0,res=0;
		while(i<n) {
			while(!st.empty()&&a[i]>=a[st.top()]) {
				st.pop();
			}
			if(st.empty()) b[i]=i+1;
			else {
				b[i]=i-st.top();
			}
			st.push(i);
			i++;
		}
		for(int i=0;i<n;i++){
			cout << b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}