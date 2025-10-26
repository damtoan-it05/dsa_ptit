#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct Node{
	char data;
	Node* left;
	Node* right;
	Node(char c){
		data=c;
		left=right=nullptr;
	}	
};
typedef struct Node* node;
void IN(node root){
	if(root==nullptr){
		return;
	}
	IN(root->left);
	cout << root->data;
	IN(root->right);
}
void Test(){
	string s;
	cin >> s;
	stack<node> st;
	for(char x:s){
		if(isalpha(x)){
			node a= new Node(x);
			st.push(a);
		}
		else{
			node a= new Node(x);
			node tmp1=st.top();st.pop();
			node tmp2=st.top();st.pop();
			a->left=tmp2;
			a->right=tmp1;
			st.push(a);
		}
	}
	IN(st.top());
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}