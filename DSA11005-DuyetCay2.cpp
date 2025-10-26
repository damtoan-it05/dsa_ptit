#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct Node{
	int data,L,R;
	Node* left;
	Node* right;
	Node(int x,int y,int z){
		data=x;
		L=y;R=z;
		left=right=nullptr;
	}
};
Node* Tree(int Io[],int Lo[],int n){
	map<int,int> mp;
	for(int i=0;i<n;i++){
		mp[Io[i]]=i;
	}
	Node* r=new Node(Lo[0],0,n-1);
	queue<Node*> q;
	q.push(r);
	int idx=1;
	while(!q.empty()){
		auto it=q.front();q.pop();
		int cur=mp[it->data];
		if(cur > it->L){
			it->left=new Node(Lo[idx++],it->L,cur-1);
			q.push(it->left);
		}
		if(cur < it->R){
			it->right=new Node(Lo[idx++],cur+1,it->R);
			q.push(it->right);
		}
	}
	return r;
}
void PostOrder(Node* r){
	if(!r){
		return;
	}
	PostOrder(r->left);
	PostOrder(r->right);
	cout << r->data << " ";
}
void Test(){
	int n;
	cin >> n;
	int Io[n],Lo[n];
	for(int &i:Io){
		cin >> i;
	}
	for(int &i:Lo){
		cin >> i;
	}
	Node* r=Tree(Io,Lo,n);
	PostOrder(r);
	cout << endl;
}
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		Test();
	}
}