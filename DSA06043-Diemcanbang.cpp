#include<bits/stdc++.h>
using namespace std;
void Test(){
	int n;
	cin >> n;
	vector<int> v(n);
	long long s=0,a=0;
	for(auto &i:v){
		cin >> i;
		s+=i;
	}
	for(int i=0;i<n;i++){
		a+=v[i];
		if(a==s){
			cout << i+1;
			return;
		}
		s-=v[i];
	}
	cout << "-1";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Test();
		cout << endl;
	}
}