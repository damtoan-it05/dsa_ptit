#include<bits/stdc++.h>
using namespace std;
void Bubblesort(int a[], int n){
	for(int i=1;i<n;i++){
	  int tmp=1;
		for(int j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				tmp=0;
			}
		}
		if(tmp) break;
		else{
		  cout << "Buoc " << i << ": ";
				for(int k=0;k<n;k++){
					cout << a[k] << " ";
				}
				cout << endl;
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	Bubblesort(a,n);
	return 0;
}