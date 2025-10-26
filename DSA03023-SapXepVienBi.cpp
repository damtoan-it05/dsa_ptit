#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int cnt_X = 0, cnt_T = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'X'){
            ++cnt_X;
        }
        else if(s[i] == 'T'){
            ++cnt_T;
        }
    }
    int res = 0;
    for(int i = 1; i <= cnt_X; i++){
        if(s[i] == 'T'){
            int j = cnt_X + 1;
            while(s[j] != 'X'){
                ++j;
            }
            swap(s[i], s[j]);
            ++res;
        }
        else if(s[i] == 'D'){
            int j = n;
            while(s[j] != 'X'){
                --j;
            }
            swap(s[i], s[j]);
            ++res;
        }
    }
    for(int i = (cnt_X + 1); i <= (cnt_X + cnt_T); i++){
        if(s[i] == 'D'){
            int j = n;
            while(s[j] != 'X'){
                --j;
            }
            swap(s[i], s[j]);
            ++res;
        }
    }
    cout << res << endl;
}