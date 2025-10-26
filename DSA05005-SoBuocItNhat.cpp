#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n],d[n]={};
		for(int i=0;i<n;i++){
			cin >> a[i];
			d[i]=1;		
		}
		int res=0;
		for(int i=1;i<n;i++){
			int tmp=0;
			for(int j=0;j<i;j++){
				if(a[i]>=a[j]){
					tmp=max(tmp,d[j]);
				}
			}
			d[i]+=tmp;
			res=max(res,d[i]);
		}
		cout << n-res << endl;
	}
}