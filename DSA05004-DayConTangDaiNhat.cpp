#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				b[i]=max(b[i],b[j]+1);
			}
		}
	}
	int s=0;
	for(int i=0;i<n;i++){
		s=max(s,b[i]);
	}
	cout << s;
}