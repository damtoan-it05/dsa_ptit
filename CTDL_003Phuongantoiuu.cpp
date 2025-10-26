#include<bits/stdc++.h>
using namespace std;
int n,w,s=0;
int a[101],c[101],b[101]={0}, xopt[101];
void check(){
	int tong=0,wei=0;
	for(int i=1;i<=n;i++){
		tong+=c[i]*b[i];
		wei+=a[i]*b[i];
	}
	if(wei<=w&&tong>s){
		s=tong;
		for(int i=1;i<=n;i++){
			xopt[i]=b[i];
		}
	}
}
void DFS(int i){
	for(int j=0;j<=1;j++){
		b[i]=j;
		if(i==n){
			check();
		}
		else DFS(i+1);
	}
}
int main() {
	cin >> n >> w;
	for(int i=1; i<=n; i++) {
	    cin >> c[i];
	}
	for(int i=1; i<=n; i++) {
	    cin >> a[i];
	}
	DFS(1);
	cout << s << endl;
	for(int i=1;i<=n;i++){
		cout << xopt[i] <<" ";
	}
}