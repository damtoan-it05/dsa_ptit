#include<iostream>
#include<vector>
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
void AddNode(node r,int a,int b,char c){
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
void BFS(node a){
	queue<node> q;
	q.push(a);
	while(!q.empty()){
		node tmp=q.front();q.pop();
		cout << tmp->data << " ";
		if(tmp->left!=nullptr) q.push(tmp->left);
		if(tmp->right!=nullptr)q.push(tmp->right);
	}
}
void Test(){
	int n;
	cin >> n;
	int a,b;
	char c;
	node r= nullptr;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		if(r==nullptr){
			r= new Node(a);
		}
		AddNode(r,a,b,c);
	}
	BFS(r);
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}