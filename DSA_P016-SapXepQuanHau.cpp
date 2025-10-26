#include<iostream>
#include<algorithm>
using namespace std;
int a[9][9],b[9],cot[9],d1[16],d2[16],s;
void ktao(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=20;i++) cot[i]=1;
	for(int i=1;i<=20;i++) d1[i]=1;
	for(int i=1;i<=20;i++) d2[i]=1;
}
void result(){
	int c=0;
	for(int i=1;i<=8;i++){
		c+=a[i][b[i]];
	}
	s=max(s,c);
}
void Try(int i){
	for(int j=1;j<=8;j++){
		if(cot[j]&&d1[i-j+8]&&d2[i+j-1]){
			cot[j]=d1[i-j+8]=d2[i+j-1]=0;
			b[i]=j;
			if(i==8) result();
			else Try(i+1);
			cot[j]=d1[i-j+8]=d2[i+j-1]=1;
		}
	}
}
 int main(){
 	int t,T=1;
 	cin >> t;
 	while(t--){
 		ktao();
 		s=0;
 		Try(1);
 		cout << "Test " << T++  <<  ": ";
 		cout << s << endl;
	} 
 }