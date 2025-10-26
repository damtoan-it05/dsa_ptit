#include<iostream>
#include<queue>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a[26]={};
		for(char c:s){
			a[c-'A']++;
		}
		priority_queue<int> q;
		for(int i=0;i<26;i++){
			if(a[i]>0) q.push(a[i]);
		}
		while(n--&&!q.empty()){
			int tmp=q.top();q.pop();
			tmp--;
			if(tmp>0) q.push(tmp);
		}
		long long res=0;
		while(!q.empty()){
			long long tmp=q.top();q.pop();
			tmp*=tmp;
			res+=tmp; 
		}
		cout << res << endl;
	}
}