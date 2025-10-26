#include<iostream>
#include<map>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data=x;
		left=right=NULL;
	}
};
typedef struct Node* node;
void Add(node &it,int n){
	map<int,node> mp;
	int a,b;char c;
	for(int i=0;i<n;i++){
		cin >> a >> b >> c;
		if(mp.find(a)==mp.end()){ // neu khong thay
			it=new Node(a);
			mp[a]=it;
			if(c=='L'){
				it->left=new Node(b);
				mp[b]=it->left;
			}
			else{
				it->right=new Node(b);
				mp[b]=it->right;
			}
		}
		else{ // neu thay
			if(c=='L'){
				mp[a]->left=new Node(b);
				mp[b]=mp[a]->left;
			}
			else{
				mp[a]->right=new Node(b);
				mp[b]=mp[a]->right;
			}
		}
	}
}
void Sum(int &sum,node r){
	if(r==NULL) return;
	if(r->right && r->right->left==NULL && r->right->right==NULL){
		sum+=r->right->data;
	}
	Sum(sum,r->left);
	Sum(sum,r->right);
}
void Test(){
	int n;
	cin >> n;
	node r=NULL;
	Add(r,n);
	int sum=0;
	Sum(sum,r);
	cout << sum << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		Test();
	}
}