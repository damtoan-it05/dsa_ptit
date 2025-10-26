#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	t=1;
	while(t--){
		int n,c,s=0;
		cin >> c >> n;
		int a[n],d[c+1]={};
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		d[0]=1;
		for(int i=0 ;i<n;i++){
			for(int j=c;j>=a[i];j--){
				if(d[j-a[i]]){
					d[j]=1;
				}
			}
		}
		for(int i=c;i>=0;i--){
			if(d[i]){
				cout << i << endl;
				break;
			}
		}
	}
}