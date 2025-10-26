#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
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
bool check(node r1, node r2){
	if(r1==nullptr && r2==nullptr) return true;
	else if(r1!=nullptr || r2!=nullptr){
		return ((r1->data==r2->data) && check(r1->left,r2->left) && check(r1->right,r2->right)); 
	}
	return false;
}
void Test(){
	int n,m;
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
	cin >> m;
	node r1=nullptr;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		if(r1==nullptr){
			r1=new Node(a);
		}
		Add(r1,a,b,c);
	}
	if(check(r,r1)) cout << 1;
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