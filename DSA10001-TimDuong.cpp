#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
char b[505][505];
pair<int,int> st;
pair<int,int> fs;
struct Path{
	int x,y,cnt;
	char c;
};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string s = "DLRU";


bool BFS(int i,int j){
	queue<Path> q;
	q.push({i,j,0,' '});
	while(!q.empty()){
		Path a=q.front();q.pop();
		if(a.x==fs.first&&a.y==fs.second){
			return true;
		}
		for(int k=0;k<4;k++){
			int i1=a.x+dx[k];
			int j1=a.y+dy[k];
			if(i1>=1&&i1<=n &&j1>=1&&j1<=m &&b[i1][j1]!='*'){
				if(a.c==' '|| a.c==s[k]){
					q.push({i1,j1,a.cnt,s[k]});
				}
				else if(a.cnt<=1){
					q.push({i1,j1,a.cnt+1,s[k]});
				}
			}
		}
	}
	return false;	
}

void Test(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> b[i][j];
			if(b[i][j]=='S'){
				st={i,j};
			}
			if(b[i][j]=='T'){
				fs={i,j};
			}
		}
	}
	if(BFS(st.first,st.second)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}