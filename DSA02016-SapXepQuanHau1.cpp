#include<iostream>
using namespace std;
int n,x[100],cot[100], d1[100], d2[100],cnt;
void Try(int i){
	for(int j=1;j<=n;j++){
		if(cot[j] && d1[i-j+n] && d2[i+j-1]){
			x[i]=j;
			cot[j] = d1[i-j+n] = d2[i+j-1]=0;
			if(i==n) cnt++;
			else{
				Try(i+1);
			}
			cot[j] = d1[i-j+n] = d2[i+j-1]=1;
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cnt=0;
		cin >> n;
		for(int i=1;i<100;i++){
			cot[i] = d1[i] = d2[i]=1;
		}
		Try(1);
		cout << cnt << endl;
	}
}