#include<iostream>
using namespace std;
char a='A',b='B',c='C';
void chuyen(int n, char x, char y){
	cout << x << " -> " << y;
	cout << endl;
}
void thaphn(int n,char x,char y, char z){
	if(n==1) chuyen(1,x,z);
	else{
		thaphn(n-1,x,z,y);
		chuyen(n,x,z);
		thaphn(n-1,y,x,z);
	}
}
int main(){
	int n;
	cin >> n;
	thaphn(n,a,b,c);
}