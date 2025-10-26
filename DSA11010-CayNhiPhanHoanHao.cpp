#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data=x;
		left=right=nullptr;
	}
};
typedef struct Node* node;
void Add(node r,int a,int b,char c){
	if(r==nullptr){
		return;
	}
	if(r->data==a){
		if(c=='L') r->left=new Node(b);
		else r->right=new Node(b);
	}
	else{
		Add(r->left,a,b,c);
		Add(r->right,a,b,c);
	}
}
int level(node r){
	if(r==nullptr) return -1;
	int x=level(r->left);
	int y=level(r->right);
	return (max(x,y)+1);
}
bool check(node r){
	queue<node> q;
	map<node,int> mp;
	q.push(r);
	int h=level(r);
	while(!q.empty()){
		node it=q.front();q.pop();
		if(it->left==nullptr && it->right==nullptr){
			if (mp[it]!=h) return false;
		}
		else{
			if(it->left==nullptr || it->right==nullptr) return false;
			mp[it->left]=mp[it]+1;
			q.push(it->left);
			mp[it->right]=mp[it]+1;
			q.push(it->right);
		}
	}
	return true;
}
void Test(){
	int n;
	cin >> n;
	int a,b;char c;
	node r=nullptr;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		if(r==nullptr){
			r=new Node(a);
		}
		Add(r,a,b,c);
	}
	if(check(r)) cout << "Yes";
	else cout << "No";
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}