#include<bits/stdc++.h>
using namespace std;
int n,k,a[101], b[105],cnt=0;
bool check(){
	for(int i=1;i<k;i++){
		if(b[a[i-1]]>b[a[i]]) return false;
	}
	return true;
}
void sinh(){
	if(check()){
		cnt++;
	}
	while(true){
		int i=k-1;
		while(i>=0&&a[i]==n-k+i) i--;
		if(i<0) break;
		a[i]++;
		for(int j=i+1;j<k;j++){
			a[j]=a[j-1]+1;
		}
		if(check()){
			cnt++;
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> b[i];
		a[i]=i;
	}
	sinh();
	cout << cnt;
}