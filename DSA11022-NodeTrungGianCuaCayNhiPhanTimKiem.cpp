#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 1001;

int n, a[maxn], idx = 0;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

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

void solve(Node* root, int &cnt){
    if(root == NULL){
        return;
    }
    if(root->left != NULL || root->right != NULL){
        ++cnt;
    }
    solve(root->left, cnt);
    solve(root->right, cnt);
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
        Node* root = Build_Tree(INT_MIN, INT_MAX);
        int ans = 0;
        solve(root, ans);
        cout << ans << endl;
    }
}