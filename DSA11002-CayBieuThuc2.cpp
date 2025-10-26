#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;
    Node(string x){
        data = x;
        left = right = NULL;
    }
};

bool check(string s){
    for(char c : s){
        if(!isdigit(c)){
            return true;
        }
    }
    return false;
}

Node* BFS(string a[], int n){
    Node* root = new Node(a[0]);
    queue<Node*> Q;
    Q.push(root);
    int idx = 1;
    while((!Q.empty()) and (idx < n)){
        auto it = Q.front();
        if((it->left != NULL) and (it->right != NULL)){
            Q.pop();
            continue;
        }
        if(it->left == NULL){
            it->left = new Node(a[idx++]);
            Q.push(it->left);
        }
        else{
            it->right = new Node(a[idx++]);
            Q.push(it->right);
        }
    }
    return root;
}

void Post_Order(Node* root, vector<string> &res){
    if(!root) return;
    Post_Order(root->left, res);
    Post_Order(root->right, res);
    res.push_back(root->data);
}

ll Calc(ll a, ll b, string c){
    if(c == "+") return a + b;
    else if(c == "-") return a - b;
    else if(c == "*") return a * b;
    return a / b;
}

void solve(Node* root){
    vector<string> ans;
    Post_Order(root, ans);
    stack<ll> stk;
    for(auto x : ans){
        if(check(x)){
            ll a = stk.top(); stk.pop();
            ll b = stk.top(); stk.pop();
            stk.push(Calc(b, a, x));
        }
        else{
            stk.push(stoll(x));
        }
    }
    cout << stk.top() << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        string a[n];
        for(auto &x : a){
            cin >> x;
        }
        Node* root = BFS(a, n);
        solve(root);
    }
}