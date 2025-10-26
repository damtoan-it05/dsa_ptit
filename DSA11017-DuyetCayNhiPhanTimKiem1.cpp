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

int n, preorder[maxn], idx;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> preorder[i];
    }
}

Node* Build_BST_Preorder(int L, int R){
    if(idx >= n){
        return nullptr;
    }
    int x = preorder[idx];
    if((x <= L) || (x >= R)){
        return nullptr;
    }
    Node* root = new Node(x);
    ++idx;
    root->left = Build_BST_Preorder(L, x);
    root->right = Build_BST_Preorder(x, R);
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
        idx = 0;
        Node* root = Build_BST_Preorder(0, INT_MAX);
        Postorder(root);
        cout << endl;
    }
}