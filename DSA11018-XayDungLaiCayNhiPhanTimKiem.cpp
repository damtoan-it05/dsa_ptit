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

Node* Insert_Node(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }
    if(root->data > key){
        root->left = Insert_Node(root->left, key);
    }
    else{
        root->right = Insert_Node(root->right, key);
    }
    return root;
}

void Pre_Order(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    Pre_Order(root->left);
    Pre_Order(root->right);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        Node* root = NULL;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            root = Insert_Node(root, x);
        }
        Pre_Order(root);
        cout << endl;
    }
}