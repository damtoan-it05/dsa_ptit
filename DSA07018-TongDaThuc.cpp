#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

vector<string> Tach_Dau(string s){
    vector<string> ans;
    stringstream ss(s);
    string token;
    while(getline(ss, token, '+')){
        ans.push_back(token);
    }
    return ans;
}

vector<string> Tach_So(string s){
    vector<string> ans;
    for(auto &x : s){
        if(!isdigit(x)){
            x = ' ';
        }
    }
    stringstream ss(s);
    string token;
    while(ss >> token){
        ans.push_back(token);
    }
    return ans;
}

map<int,int> solve(string s1, string s2){
    map<int,int> res;
    vector<string> tmp1 = Tach_Dau(s1);
    vector<string> tmp2 = Tach_Dau(s2);
    for(auto it : tmp1){
        vector<string> vt1 = Tach_So(it);
        res[stoi(vt1[1])] += stoi(vt1[0]);
    }
    for(auto it : tmp2){
        vector<string> vt2 = Tach_So(it);
        res[stoi(vt2[1])] += stoi(vt2[0]);
    }    
    return res;
}

int main(){
    int TC;
    cin >> TC;
    cin.ignore();
    while(TC--){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        map<int,int> res = solve(s1, s2); // map dùng để lưu cặp {số mũ, hệ số}
        vector<pair<int,int>> vt;
        for(auto x : res){
            vt.push_back(x);
        }
        for(int i = vt.size() - 1; i >= 0; i--){
            cout << vt[i].second << "*x^" << vt[i].first;
            if(i != 0){
                cout << " + ";
            }
            else{
                cout << endl;
            }
        }
    }
}