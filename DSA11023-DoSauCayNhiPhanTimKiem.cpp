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

int Height(Node* root){
    if(root == NULL){
        return -1;
    }
    int h1 = Height(root->left);
    int h2 = Height(root->right);
    return max(h1, h2) + 1;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        Node* root = NULL;
        for(auto x : a){
            root = Insert_Node(root, x);
        }
        cout << Height(root) << endl;
    }
}