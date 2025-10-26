#include<bits/stdc++.h>
using namespace std;
int maxx(int a[], int i,int k){
	int tmp=a[i];
	while(i<k){
		if(a[i] > tmp) tmp=a[i];
		else i++;
	}
	return tmp;
}
int main(){
	int t;
	cin >> t;
	while(t--){
	 	int n, k;
	 	cin >> n >> k;
	 	int a[n];
	 	for(int i=0;i<n;i++){
	 		cin >> a[i]; 
		}
		for(int i=0;i<n-k+1;i++){
			int tmp=maxx(a,i,k+i);
			cout << tmp << " ";
		}
		cout << endl;
	}
}