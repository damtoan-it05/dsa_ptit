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
void AddNode(Node* r,int a,int b,char c){
	if(r==nullptr){
		return;
	}
	if(r->data==a){
		if(c=='L'){
			r->left=new Node(b);
		}
		else{
			r->right=new Node(b);
		}
	}
	else{
		AddNode(r->left,a,b,c);
		AddNode(r->right,a,b,c);
	}
}
int level(Node* r){
	if(r==nullptr){
		return -1;
	}
	int x=level(r->left);
	int y=level(r->right);
	return (max(x,y)+1);
}
bool check(Node* r){
	queue<Node*> q;
	map<Node*,int> mp;
	q.push(r);
	int h=level(r);
	mp[r]=0;
	while(!q.empty()){
		auto it=q.front();q.pop();
		if(it->left==nullptr&&it->right==nullptr){
			if(mp[it]!=h) return false;
		}
		if(it->left!=nullptr){
			mp[it->left]=mp[it]+1;
			q.push(it->left);
		}
		if(it->right!=nullptr){
			mp[it->right]=mp[it]+1;
			q.push(it->right);
		}	
	}
	return true;
}
void Test(){
	int n;
	cin >> n;
	int a,b;
	char c;
	Node* r=nullptr;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		if(r==nullptr){
			r=new Node(a);
		}
		AddNode(r,a,b,c);
	}
	if(check(r)) cout << 1;
	else cout << 0;
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}