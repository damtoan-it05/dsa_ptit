#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n],d[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		d[0]=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>a[i-1]) d[i]=d[i-1]+a[i];
			else{
				int j=i-1;
				while(j>=0&&a[j]>a[i]) j--;
				d[i]=d[j]+a[i];
			}
		}
		int s=0;
		for(int i=0;i<n;i++){
			if(d[i]>s) s=d[i];
		}
		cout << s << endl;
	}
}