#include<bits/stdc++.h>
using namespace std;
vector<string> v;
void Dequy(int a[], int n){
	if(n==0){
		return;
	}
	else{
		string s="[";
		for(int i=0;i<n;i++){
			s+=to_string(a[i]);
			if(i!=n-1) s+=" ";
		}
		s+="]";
		v.push_back(s);
		for(int i=0;i<n-1;i++){
			a[i]+=a[i+1];
		}
		n--;
		Dequy(a,n);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		Dequy(a,n);
		for(int i=v.size()-1;i>=0;i--){
			cout << v[i] << " ";
		}
		cout << endl;
		v.clear();
	}
}