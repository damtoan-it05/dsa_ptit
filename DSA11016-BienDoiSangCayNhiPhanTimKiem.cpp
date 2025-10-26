#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void Add_Node(Node* root, int u, int v, char c){
    if(!root) return;
    if(root->data == u){
        if(c == 'L'){
            root->left = new Node(v);
        }
        else{
            root->right = new Node(v);
        }
    }
    else{
        Add_Node(root->left, u, v, c);
        Add_Node(root->right, u, v, c);
    }
}

void Pre_Order(Node* root, vector<int> &res){
    if(!root) return;
    res.push_back(root->data);
    Pre_Order(root->left, res);
    Pre_Order(root->right, res);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        Node* root = NULL;
        for(int i = 0; i < n; i++){
            int u, v; char c;
            cin >> u >> v >> c;
            if(!root){
                root = new Node(u);
            }
            Add_Node(root, u, v, c);
        }
        vector<int> res;
        Pre_Order(root, res);
        sort(begin(res), end(res));
        for(auto x : res){
            cout << x << " ";
        }
        cout << endl;
    }
}