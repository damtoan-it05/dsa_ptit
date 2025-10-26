#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,s,m;
		cin >> n >> s >> m;
		// so luong thuc toi da mua duoc trong s ngay
		int x=(s-s/7)*n;
		// so luong thuc can thiet trong s ngay
		int y=m*s;
		if(y>x) cout <<"-1" << endl;
		else{
			int cnt=0,res=0;
			while(res<y){
				res+=n;
				cnt++;
			}
			cout << cnt << endl;
		}
	} 
}