#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<int,vector<int>,greater<int>> pq;
		int x;
		for(int i=0;i<n;i++){
			cin >> x;
			pq.push(x);
		}
		long long s=0;
		while(pq.size()>1){
			int a=pq.top();pq.pop();
			int b=pq.top();pq.pop();
			s+=a+b;
			pq.push(a+b);
		}
		cout << s << endl;
	} 
}