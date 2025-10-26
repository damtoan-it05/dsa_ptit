#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	int a[n],b[n+1],s=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]<0){
			a[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
	}
	while(k--){
		int x,y;
		cin >> x >> y;
		cout << b[y]-b[x-1] << endl;
	}
}