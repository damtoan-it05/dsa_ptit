#include<iostream>
using namespace std;
int n,a[1005],s;
void dem(int l, int r){
	int mid=(r+l)/2;
	if(!a[mid]) s++;
	if(l==r){
		return;
	}
	if(a[mid]){
		dem(l,mid);
	}
	else{
		s=mid;
		dem(mid+1,r);
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		s=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		dem(1,n);
		cout << s << endl;
	} 
}