#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	  while(t--){
	  	int n,k,tmp,cnt;
	  	cin >> n >> k;
	  	for(int i=0;i<n;i++){
	  		cin >> tmp;
	  		if(tmp==k) cnt = i+1;
    	}
    	cout << cnt << endl;
	}
}