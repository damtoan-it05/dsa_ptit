#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int maxn = 101;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        string s1, s2;
        cin >> s1 >> s2;
        int len1 = s1.size(), len2 = s2.size();
        s1 = " " + s1; s2 = " " + s2;
        int dp[maxn][maxn];
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = i + j;
                }
                else if(s1[i] == s2[j]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
            }
        }
        cout << dp[len1][len2] << endl;
    }
}