// Duyet cac xau nhi phan do dai n:Quay lui
#include<iostream>
using namespace std;
int n, x[100];
void Init(){
	cin >> n;
}
void result(){
	for(int i=1;i<=n;i++){
		cout << x[i] << " ";
	}
	cout << endl;
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
	Init();
	Try(1);
	return 0;
}