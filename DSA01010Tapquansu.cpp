#include<bits/stdc++.h>
using namespace std;
int n,k,a[45], b[45];
void sinh() {
	int i=k-1,cnt=0;
	while(i>=0&&a[i]==n-k+i+1) i--;
	if(i<0) {
		cout << k << endl;
	} 
	else {
		a[i]++;
		for(int j=i+1; j<k; j++) {
			a[j]=a[j-1]+1;
		}
		for(int i=0; i<k; i++) {
			if(b[a[i]]==1) {
				cnt++;
			}
		}
		cnt=k-cnt;
		cout << cnt << endl;
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<45; i++) b[i]=0;
		for(int i=0; i<k; i++) {
			cin >> a[i];
			b[a[i]]=1;
		}
		sinh();
	}
}