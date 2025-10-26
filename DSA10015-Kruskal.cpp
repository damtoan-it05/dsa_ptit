#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

// dung struct neu khong muon bi MLE
struct Data{
	int x,y,z;
};
int v,e,pre[105],sz[105];
long long dh;
vector<Data> vc;
 // dung DSU:
void Makeset(){
	for(int i=1;i<=v;i++){
		pre[i]=i;
		sz[i]=1;
	}
}
int Findset(int a){
	if(a==pre[a]) return a;
	return pre[a]=Findset(pre[a]);
}
bool Union(int a,int b){
	a=Findset(a);
	b=Findset(b);
	if(a==b) return false;
	if(sz[a]<sz[b]){
		swap(a,b);
	}
	pre[b]=a;
	sz[a]+=sz[b];
	return true;
}

bool cmp(Data a,Data b){
	return a.z <b.z;
}

void Kruskal(){
	dh=0;
	int cnt=0;
	sort(vc.begin(),vc.end(),cmp); // sap xep tang dan theo trong so
	for(int i=0;i<e;i++){
		Data it=vc[i];
		if(cnt==v-1) break;
		int x=it.x,y=it.y; // lay canh
		if(Union(x,y)){
			dh+=it.z;
			cnt++;
		}
	}
}

void Test(){
	cin >> v >> e;
	vc.clear();
	for(int i=1;i<=e;i++){
		int x,y,z;
		cin >> x >> y >> z;
		vc.push_back({x,y,z});
	}
	Makeset();
	Kruskal();
	cout << dh << endl;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}