#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll cnt = 0;

void Merge(int a[], int l, int m, int r){
	vector<int> vt;
	int i = l, j = m + 1;
	while((i <= m) and (j <= r)){
		if(a[i] <= a[j]){
			vt.push_back(a[i]);
			++i;
		}
		else{
			vt.push_back(a[j]);
			++j;
			cnt += 1ll * (m - i + 1);
		}
	}
	while(i <= m){
		vt.push_back(a[i]);
		++i;		
	}
	while(j <= r){
		vt.push_back(a[j]);
		++j;		
	}
	int idx = 0;
	for(int k = l; k <= r; k++){
		a[k] = vt[idx++];
	}
}

void Merge_Sort(int a[], int l, int r){
	if(l == r) return;
	int m = (l + r)/2;
	Merge_Sort(a, l, m);
	Merge_Sort(a, m + 1, r);
	Merge(a, l, m, r);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
    	int n;
    	cin >> n;
    	int a[n];
    	for(auto &x : a){
    		cin >> x;
		}
		cnt = 0;
		Merge_Sort(a, 0, n - 1);
		cout << cnt << endl;
	}
}