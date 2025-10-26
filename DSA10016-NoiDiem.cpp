#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int n,pre[105],sz[105];
struct Data {
	int x,y;
	double w;
};
vector<Data> vt;

void Makeset() {
	for(int i=1; i<=n; i++) {
		pre[i]=i;
		sz[i]=1;
	}
}

int Findset(int a) {
	if(a==pre[a]) return a;
	return pre[a]=Findset(pre[a]);
}

bool Union(int a,int b) {
	a=Findset(a);
	b=Findset(b);
	if(a==b) return false;
	if(sz[a]<sz[b]) {
		swap(a,b);
	}
	pre[b]=a;
	sz[a]+=sz[b];
	return true;
}

bool cmp(Data a,Data b) {
	return a.w<b.w;
}

void Kruskal() {
	double dh=0;
	int cnt=0;
	sort(vt.begin(),vt.end(),cmp);
	for(Data c:vt) {
		if(cnt==n-1) break;
		int u,v;
		u=c.x;
		v=c.y;
		if(Union(u,v)) {
			dh+=c.w;
			cnt++;
		}
	}
	cout << fixed << setprecision(6) << dh << endl;
}

void Test() {
	cin >> n;
	Makeset();
	vt.clear();
	pair<double,double> a[n+1];
	for(int i=1; i<=n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			double x=a[i].first-a[j].first,y=a[i].second-a[j].second,res;
			res=sqrt(x*x+y*y);
			vt.push_back({i,j,res});
		}
	}
	Kruskal();
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Test();
	}
}