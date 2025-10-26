#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> BDN;
void NP() {
	queue<long long> q;
	q.push(1);
	while(q.front()<1e18) {
		long long tmp=q.front();
		BDN.push_back(tmp);
		q.pop();
		q.push(tmp*10);
		q.push(tmp*10+1);
	}
}
int main() {
	int t;
	cin >> t;
	NP();
	while(t--) {
		long long s;
		cin >> s;
		int cnt=0;
		for(long long x:BDN){
			if(x<=s) cnt++;
			else break;
		}
		cout << cnt << endl;
	}
}