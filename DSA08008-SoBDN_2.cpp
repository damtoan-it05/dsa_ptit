#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
void NP(int n) {
	queue<long long> q;
	q.push(1);
	while(1) {
		long long tmp=q.front();
		if(tmp%n==0){
			cout << tmp << endl;
			return;
		}
		q.pop();
		q.push(tmp*10);
		q.push(tmp*10+1);
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		NP(n);
	}
	return 0;
}