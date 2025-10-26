#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &v, int l,int mid, int r){
	int n1=mid-l+1,n2=r-mid;
	vector<int> a(n1),b(n2);
	for(int i=0;i<n1;i++){
		a[i]=v[l+i];
	}
	for(int j=0;j<n2;j++){
		b[j]=v[mid+1+j];
	}
	int i=0,j=0,k=l;
	while(i<n1&&j<n2){
		if(a[i]<b[j]){
			v[k]=a[i];
			i++;
		}
		else{
			v[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		v[k]=a[i];
		i++;
		k++;
	}
	while(j<n2){
		v[k]=b[j];
		j++;
		k++;
	}
}
void Mergesort(vector<int> &v,int l,int r){
	if(l>=r) return;
	int mid=(l+r)/2;
	Mergesort(v,l,mid);
	Mergesort(v,mid+1,r);
	Merge(v,l,mid,r);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		Mergesort(v,0,n-1);
		for(auto x : v) cout << x << " ";
		cout << endl;
	}
}