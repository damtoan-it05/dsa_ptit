#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		map<char,int> mp;
		for(int i=0;i<s.size();i++){
			mp[s[i]]++;
		}
		int ok=1,n=s.size()+1;
		for(auto x:mp){
			if(x.second > n/2){
				cout << "-1" << endl;
				ok=0;
				break;
			}
		}
		if(ok) cout << "1" << endl;
	} 
}