#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n+1]={0},cnt=0,x;
	for(int i=1;i<=n;i++){
		cin >> x;
		a[x]=a[x-1]+1;
		if(a[x]>cnt) cnt=a[x];
	}
	cout << n-cnt << endl;
}