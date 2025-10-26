#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s;
        cin >> s;
        int ans = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                ++cnt1;
            }
            else{
                ++cnt2;
            }
            if(cnt2 > cnt1){
                int j = i + 1;
                while(s[j] == s[i]){
                    ++j;
                }
                ans += j - i;
                swap(s[i], s[j]);
                ++cnt1; --cnt2;
            }
        }
        cout << ans << endl;
    }
}