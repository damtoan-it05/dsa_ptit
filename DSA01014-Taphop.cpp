#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[25],cnt;
void check(){
	int tong=0;
	for(int i=0;i<k;i++){
		tong+=a[i];
	}
	if(tong==s) cnt++;
}
void sinh(){
	check();
	while(true){
		int i=k-1;
		while(i>=0&&a[i]==n-k+i+1) i--;
		if(i<0) break;
		a[i]++;
		for(int j=i+1;j<k;j++){
			a[j]=a[j-1]+1;
		}
		check();
	}
}
int main() {
	cin >> n >> k >> s;
	while(n&&k&&s){
		cnt=0;
		for(int i=0;i<k;i++){
			a[i]=i+1;
		}
		if(n>=k) sinh();
		cout << cnt << endl;
		cin >> n >> k >> s;
	}
}