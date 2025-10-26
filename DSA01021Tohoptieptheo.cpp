#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,k,cnt=0;
		cin >> n >> k;
		int a[k],b[50];
		for(int i=0;i<50;i++) b[i]=0;
		for(int i=0; i<k; i++) {
			cin >> a[i];
			b[a[i]]=1;// danh dau mang ban dau
		}
		int i=k-1;
		while(i>=0&&a[i]==n-k+i+1) i--;// tim vi tri can tang
		a[i]++;
		if(i<0) {// neu la to hop cuoi
			cout << k << endl;
		} 
		else {
			for(int j=i+1; j<k; j++) { // tao ra to hop tiep theo
				a[j]=a[j-1]+1;
			}
			for(int j=0;j<k;j++){// so sanh tim so ko thay doi
				if(b[a[j]]==1) cnt++;
			}
			cout << k-cnt << endl;// so moi = k - so thay doi
		}
	}
}