#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

string s;
char X[4] = {'+', '-', '*', '/'};

bool check(){
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(5, 2));
    int c = stoi(s.substr(10, 2));
    if(s[3] == '+'){
        return (a + b) == c;
    }
    else if(s[3] == '-'){
        return (a - b) == c;
    }
    else if(s[3] == '*'){
        return (a * b) == c;
    }
    else{
        if((a % b) != 0) return false;
        return (a / b) == c;
    }
}

bool flag = true;

void Try(int i){
    if(!flag){
        return;
    }
    if(i == s.size()){
        if(check()){
            cout << s << endl;
            flag = false;
        }
        return;
    }
    if(s[i] != '?'){
        Try(i + 1);
    }
    else{
        if(i == 3){
            for(int j = 0; j < 4; j++){
                s[i] = X[j];
                Try(i + 1);
                s[i] = '?';
            }
        }
        else{
            for(char j = '0'; j <= '9'; j++){
                if(j == '0'){
                    if((i == 0) or (i == 5) or (i == 10)){
                        continue;
                    }
                }
                s[i] = j;
                Try(i + 1);
                s[i] = '?';
            }
        }
    }
}

int main(){
    int TC;
    cin >> TC;
    cin.ignore();
    while(TC--){
        getline(cin, s);
        flag = true;
        Try(0);
        if(flag){
            cout << "WRONG PROBLEM!" << endl;
        }
    }
}