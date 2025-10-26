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
bool check(node r){
	queue<node> q;
	q.push(r);
	while(!q.empty()){
		node it=q.front();q.pop();
		if(it->left==nullptr&&it->right==nullptr){
			continue;
		}
		else{
			if(it->left==nullptr||it->right==nullptr) return false;
			q.push(it->left);
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
	if(check(r)) cout << 1;
	else cout << 0;
	cout << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Test();
	}
}