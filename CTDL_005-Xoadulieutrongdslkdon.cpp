#include<bits/stdc++.h>
using namespace std;
int t,k;
struct Node {
	int data;
	Node *next;
};
typedef struct Node* node;
node Makenode(int x){
	node tmp= new Node();
	tmp->data=x;
	tmp->next=NULL;
	return tmp;
}
void insertLast(node &a,int x){
	node tmp= Makenode(x);
	if(a==NULL){
		a=tmp;
	}
	else{
		node p=a;
		while(p->next !=NULL){
			p=p->next;
		}
		p->next=tmp;
	}
}
void in(node a){
	while(a!=NULL){
		int tmp=a->data;
		if( tmp!= k) cout << tmp << " ";
		a=a->next;
	}
	cout << endl;
}
int main() {
	node head = NULL;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		insertLast(head,n);
	}
	cin >> k;
	in(head);
	return 0;
}