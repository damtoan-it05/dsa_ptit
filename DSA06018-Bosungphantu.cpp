#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,tmp,cnt=0;
		cin >> n;
		set<int> se;
		for(int i=0;i<n;i++){
			cin >> tmp;
			se.insert(tmp);
		}
		int l = *se.begin();
		for(auto x : se){
			while(l!=x){
			   cnt++;
			   l++;
			}
			l++;
		}
		cout << cnt << endl;
	}
}