#include<bits/stdc++.h>
using namespace std;
int dem(int x, int b[], int c[], int m){
	if(x==0) return 0;
	else if(x==1) return c[0];
	int it=upper_bound(b,b+m,x)-b;
	int s=m-it;
	s+=(c[0]+c[1]);
	if(x==2) s-=(c[3]+c[4]);
	else if(x==3) s+=c[2];
	return s;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n],b[m],c[5]={} ;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<m;i++){
			cin >> b[i];
			if(b[i]<5){
				c[b[i]]++;
			}
		}
		sort(b,b+m);
		long long s=0;
		for(int i=0;i<n;i++){
			s+=dem(a[i],b, c, m);
		}
		cout << s << endl;
	}
}