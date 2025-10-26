// Duyet cac hoan vi :Quay lui
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100] ,x[100];
void Init() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		a[i]=true;
	}
}
void result() {
	for(int i=1; i<=n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}
void Try(int i) {
	for(int j=1; j<=n; j++) {
		if(a[j]) {
			x[i]=j;a[j]=false;
			if(i==n) {
				result();
			} else Try(i+1);
			a[j]=true;
		}
	}
}
using namespace std;
int main() {
	Init();
	Try(1);
	return 0;
}