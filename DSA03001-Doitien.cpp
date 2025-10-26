#include<iostream>
using namespace std;
int n, a[10]={1,2,5,10,20,50,100,200,500,1000};
void Init(){
	cin >> n;
}
void Greedy(){
	int cnt=0;
	for(int i=9;i>=0;i--){
		cnt+=n/a[i];
		n%=a[i];
		if(n==0) break;
	}
	cout << cnt;
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