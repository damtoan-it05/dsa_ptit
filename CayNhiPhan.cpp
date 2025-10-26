#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *root=NULL;
Node *MakeNode(int x){
	Node *n=new Node();
	n->data=x;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void NLR(Node *root){
	if(root != 	NULL){
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(Node *root){
	if(root != 	NULL){
		NLR(root->left);
		cout << root->data << " ";
		NLR(root->right);
	}
}
void LRN(Node *root){
	if(root != 	NULL){
		NLR(root->left);
		NLR(root->right);
		cout << root->data << " ";
	}
}

int main(){
	Node *root = MakeNode(50);
	Node *node40 = MakeNode(40);
	Node *node60 = MakeNode(60);
	Node *node30 = MakeNode(30);
	Node *node20 = MakeNode(20);
	Node *node25 = MakeNode(25);
	Node *node15 = MakeNode(15);
	Node *node65 = MakeNode(65);
	Node *node70 = MakeNode(70);
	
	root->left = node40;
	root->right = node60;
	node40->left=node30;
	node40->right=node20;
	node20->left=node25;
	node20->right=node15;
	node60->left=node65;
	node60->right=node70;
	NLR(root);
	cout << endl;
	LNR(root);
	cout << endl;
	LRN(root);
	return 0;
}