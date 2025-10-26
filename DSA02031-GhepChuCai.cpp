#include<iostream>
#include<algorithm>
using namespace std;
string s="";
void result(){
	cout << s << endl;
}
int check(char c){
  if(c!='A'&& c!='E') return 1;
  return 0;
}
void test(){
  for(int i=0;i<s.size();i++){
    if(s[i]=='A' || s[i]=='E'){
      if(i>0 && i<s.size()-1 && check(s[i-1]) && check(s[i+1])) return;
    }
  }
  result();
}
int main(){
  char x;
	cin >> x;
	for(char i='A';i<=x;i++){
	  s+=i;
	}
	do{
	  test();
	}while(next_permutation(s.begin(),s.end()));
}