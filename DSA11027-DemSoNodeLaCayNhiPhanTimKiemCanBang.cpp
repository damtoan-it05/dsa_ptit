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

Node* Build_AVL(int a[], int L, int R){
    if(L > R){
        return NULL;
    }
    int M = (L + R)/2;
    Node* root = new Node(a[M]);
    root->left = Build_AVL(a, L, M - 1);
    root->right = Build_AVL(a, M + 1, R);
    return root;
}

void Count_Leaf(Node* root, int &cnt){
    if(!root) return;
    if((!root->left) and (!root->right)) ++cnt;
    Count_Leaf(root->left, cnt);
    Count_Leaf(root->right, cnt);
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        int a[n];
        for(auto &x : a){
            cin >> x;
        }
        sort(a, a + n);
        Node* root = Build_AVL(a, 0, n - 1);
        int res = 0;
        Count_Leaf(root, res);
        cout << res << endl;
    }
}