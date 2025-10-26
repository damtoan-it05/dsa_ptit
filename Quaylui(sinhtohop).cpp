// Duyet k phan tu cua n phan tu :Quay lui
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n, k, x[100];
void Init() {
	cin >> n >> k;
	x[0]=0;
}
void result() {
	for(int i=1; i<=k; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i) {
	for(int j=x[i-1]+1; j<=n-k+1; j++) {
		x[i]=j;
		if(i==k) {
			result();
		} 
		else Try(i+1);
	}
}
using namespace std;
int main() {
	Init();
	Try(1);
	return 0;
}