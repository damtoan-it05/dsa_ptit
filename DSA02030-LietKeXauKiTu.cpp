#include<iostream>
using namespace std;
char s;
int k,x[100];
void result(){
	for(int i=1;i<=k;i++){
		cout << char(x[i]+64);
	}
	cout << endl;
}
void check(){
  for(int i=1;i<k;i++){
    if(x[i]>x[i+1]) return;
  }
  result();
}
void Try(int i, int n){
	for(int j=1;j<=n;j++){
		x[i]=j;
		if(i==k) check();
		else Try(i+1,n);
	}
}
int main(){
	cin >> s >> k;
	int n=s-'A'+1;
	Try(1,n);
}