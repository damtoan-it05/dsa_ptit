#include<iostream>
using namespace std;
int a[9];
void result(){
	for(int i=1;i<9;i++){
		if(a[i]) cout << 2;
		else cout << a[i];
		if(i==2||i==4) cout << "/";
	}
	cout << endl;
}
void check(){
	if(a[1]==0&&a[2]==0 || a[3] || a[3]==0&&a[4]==0 ||a[5]==0) return;
	else result();
}
void Try(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==8) check();
		else Try(i+1);
	}
}
int main(){
	Try(1);
	return 0;
}