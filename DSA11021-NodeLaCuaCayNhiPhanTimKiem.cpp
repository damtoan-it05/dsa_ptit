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
        left = right = NULL;
    }
};

int n, a[maxn], idx = 0;

Node* Build_Tree(int L, int R){
    if(idx >= n){
        return NULL;
    }
    Node* root = new Node(a[idx]);
    if(root->data <= L || root->data >= R){
        return NULL;
    }
    ++idx;
    root->left = Build_Tree(L, root->data);
    root->right = Build_Tree(root->data, R);
    return root;
}

void Print_Leaf(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL and root->right == NULL){
        cout << root->data << " ";
    }
    Print_Leaf(root->left);
    Print_Leaf(root->right);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        idx = 0;
        Node* root = Build_Tree(0, INT_MAX);
        Print_Leaf(root);
        cout << endl;
    }
}