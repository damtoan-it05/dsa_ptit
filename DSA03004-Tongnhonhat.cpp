#include<iostream>
#include<algorithm>
using namespace std;
int n,a[50];
void Init(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
}
void Greedy(){
	long long x1=0,x2=0;
	for(int i=0;i<n;i+=2){
		x1=x1*10+a[i];
	}
	for(int i=1;i<n;i+=2){
		x2=x2*10+a[i];
	}
	cout << x1+x2;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Init();
		Greedy();
		cout << endl;
	}
	return 0;
}