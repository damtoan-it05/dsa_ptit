// cap so nguyento
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100], x[100];
bool cmp(int a, int b){
	return a>b;
}
void Init(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
}
int ngto(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return 0;
	}
	return n>1;
}
void result(){
	int s=0;
	for(int i=1;i<=n;i++){
		s+=(a[i]*x[i]);
	}
	if(ngto(s)){
		for(int i=1;i<=n;i++){
			if(x[i]){
				cout << a[i] << " ";
			}
		}
		cout << endl;
	}
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			result();
		}
		else Try(i+1);
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