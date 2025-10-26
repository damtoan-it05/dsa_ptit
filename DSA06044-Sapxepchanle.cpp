#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,x;
	cin >> n;
	vector<int> v1,v2;
	for(int i=0; i<n; i++) {
	    cin >> x;
		if(i%2) v2.push_back(x);
		else v1.push_back(x);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int l=0,r=v2.size()-1;
	for(int i=0; i<n; i++) {
		if(i%2) {
			cout << v2[r] << " ";
			r--;
		} 
		else {
			cout << v1[l] << " ";
			l++;
		}
	}
}