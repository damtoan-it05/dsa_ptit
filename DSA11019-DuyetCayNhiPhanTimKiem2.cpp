#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 1001;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

int n, preorder[maxn];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> preorder[i];
    }
}

Node* Insert_Node(Node* root, int key){
    if(root == nullptr){
        root = new Node(key);
    }
    if(root->data > key){
        root->left = Insert_Node(root->left, key);
    }
    else if(root->data < key){
        root->right = Insert_Node(root->right, key);
    }
    return root;
}

void Postorder(Node* root){
    if(root == nullptr) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        input();
        Node* root = nullptr;
        for(int i = 0; i < n; i++){
            root = Insert_Node(root, preorder[i]);
        }
        Postorder(root);
        cout << endl;
    }
}