#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n=s.size();
		int d[n+1]={};
		if(s[0]=='0') {
			cout << "0" << endl;
			continue;
		}
		d[0]=1;d[1]=1;
		for(int i=2;i<=n;i++){
			if(s[i-1]>'0') d[i]=d[i-1];
			if(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6'){
				d[i]+=d[i-2];
			}
		}
		cout << d[n] << endl;
	}
}