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

void Add_Node(Node *root, int u, int v, char c){
    if(root == NULL){
        return;
    }
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

int res = INT_MIN;

int solve(Node* root){
    if(root == NULL){
        return 0;
    }
    int L = solve(root->left);
    int R = solve(root->right);
    if((root->left != NULL) and (root->right != NULL)){
        res = max(res, L + R + root->data);
        return root->data + max(L, R);
    }
    return root->data + ((root->left) ? L : R);
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
            if(root == NULL){
                root = new Node(u);
            }
            Add_Node(root, u, v, c);
        }
        res = INT_MIN;
        int tmp = solve(root);
        cout << res << endl;
    }
}