#include<bits/stdc++.h>
using namespace std;
void xuat(vector <int> v,int a[], int n){
	for(int i=0;i<n;i++){
		if(a[i]==1) cout << v[i] << " ";
	}
	cout << endl;
}
void sinh(vector <int> v,int k, int n){
	int cnt=0, a[n];
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	while(true){
		int i=n-1;
		while(i>=0&&a[i]>0){
			a[i]=0;
			i--;
		}
		a[i]=1;
		int sum=0;
		for(int j=0;j<n;j++){
			sum+=a[j]*v[j];
			if(k<sum) break;
		}
		if(sum==k){
			xuat(v,a, n);
			cnt++;
		}
		if(i<0){
			cout << cnt << endl;
			break;
		}
	}
}
int main(){
	int n, k,x;
    vector<int> v;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> x;
		v.push_back(x);
	}
	sinh(v,k,n);
	return 0;
}