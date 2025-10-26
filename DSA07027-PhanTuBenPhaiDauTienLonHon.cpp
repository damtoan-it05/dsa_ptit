#include<iostream>
#include<stack>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		stack<int> st;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=n-1;i>=0;i--){
			int tmp=-1;
			for(int j=i+1;j<n;j++){
				if(a[j]>a[i]){
					tmp=a[j];
					break;
				}
			}
			st.push(tmp);
		}
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
	return 0;
}