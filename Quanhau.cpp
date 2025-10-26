// Duyet cac hoan vi :Quay lui
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n ,x[100];
bool cot[100], xuoi[100], nguoc[100];
void Init() {
	cin >> n;
	fill(cot,cot+n+1,true);
	fill(xuoi,xuoi+2*n+1,true);
	fill(nguoc,nguoc+2*n+1,true);
}
void result() {
	for(int i=1; i<=n; i++) {
		cout << "(" << i << "," << x[i] << ") ";
	}
	cout << endl;
}
void Try(int i) {
	for(int j=1; j<=n; j++) {
		if(cot[j]&&xuoi[i-j+n]&&nguoc[i+j-1]) {
			x[i]=j;
			cot[j]=false;
			xuoi[i-j+n]=false;
			nguoc[i+j-1]=false;
			if(i==n) {
				result();
			} else Try(i+1);
			cot[j]=true;
			xuoi[i-j+n]=true;
			nguoc[i+j-1]=true;
		}
	}
}
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		Init();
		Try(1);
	}
	return 0;
}