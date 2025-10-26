#include<iostream>
#include<algorithm>
using namespace std;
string maxx(string s){
	string res="";
	for(int i=0;i<s.size();i++){
		if(s[i]=='5') res+='6';
		else res+=s[i];
	}
	return res;
}
string minn(string s){
	string res="";
	for(int i=0;i<s.size();i++){
		if(s[i]=='6') res+='5';
		else res+=s[i];
	}
	return res;
}
int main(){
	string n,m;
	cin >> n >> m;
	n=minn(n);
	m=minn(m);
	cout << stoi(n)+stoi(m) << " ";
	n=maxx(n);
	m=maxx(m);
	cout << stoi(n)+stoi(m);
}