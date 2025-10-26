#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data=x;
		left=right=nullptr;
	}
};
void AddNode(Node* r, int a,int b,char c) {
	if(r==nullptr) {
		return;
	}
	if(r->data==a) {
		if(c=='L') r->left=new Node(b);
		else r->right=new Node(b);
	} else {
		AddNode(r->left,a,b,c);
		AddNode(r->right,a,b,c);
	}
}
void PostOrder(Node* r) {
	stack<Node*> st1,st2;
	st1.push(r);
	while(!st1.empty()||!st2.empty()) {
		while(!st1.empty()) {
			auto it=st1.top();st1.pop();
			cout << it->data << " ";
			if(it->right!=nullptr) {
				st2.push(it->right);
			}
			if(it->left!=nullptr) {
				st2.push(it->left);
			}
		}
		while(!st2.empty() ){
			auto it=st2.top();st2.pop();
			cout << it->data << " ";
			if(it->left!=nullptr) {
				st1.push(it->left);
			}
			if(it->right!=nullptr) {
				st1.push(it->right);
			}
		}
	}
}
void Test() {
	int n;
	cin >> n;
	int a,b;
	char c;
	Node* r=nullptr;
	for(int i=0; i<n; i++) {
		cin >> a >> b >> c;
		if(r==nullptr) {
			r=new Node(a);
		}
		AddNode(r,a,b,c);
	}
	PostOrder(r);
	cout << endl;
}
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		Test();
	}
}