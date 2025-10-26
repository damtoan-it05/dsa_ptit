#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long mod=1e9+7;
int main(){
	int t;
	cin >> t;
	while(t--){
		long long n,x;
		cin >> n;
		priority_queue<long long,vector<long long> ,greater<long long>> pq;
		for(int i=0;i<n;i++){
			cin >> x;
			pq.push(x);
		}
		long long s=0,tmp;
		while(pq.size()>1){
			long long a=pq.top();pq.pop();
			long long b=pq.top();pq.pop();
			tmp=a+b;
			tmp%= mod;
			s+=tmp;
			s%=mod;
			pq.push(tmp);
		}
		cout << s << endl;
	} 
}