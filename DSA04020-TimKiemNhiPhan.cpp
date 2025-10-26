#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,ok;
void Try(int a[],int l, int r){
	if(l>r) return;
	int mid=(l+r)/2;
	if(a[mid]==k){
		cout << mid+1 << endl;
		ok=0;
		return;
	}
	else if(k>a[mid]) Try(a,mid+1,r);
	else Try(a,l,mid-1);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int a[n];
		ok=1;
		for(int i=0;i<n;i++) cin >> a[i];
		Try(a,0,n-1);
		if(ok) cout << "NO" << endl;
	} 
}