#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int Histogram(int X[], int n){
	stack<int> stk;
	int i = 0, res = 0;
	while(i < n){
		if((stk.empty()) || (X[i] >= X[stk.top()])){
			stk.push(i);
			++i;
		}
		else{
			int cur = stk.top(); stk.pop();
			if(stk.empty()){
				res = max(res, X[cur] * i);
			}
			else{
				res = max(res, X[cur] * (i - stk.top() - 1));
			}
		}
	}
	while(!stk.empty()){
		int cur = stk.top(); stk.pop();
		if(stk.empty()){
			res = max(res, X[cur] * i);
		}
		else{
			res = max(res, X[cur] * (i - stk.top() - 1));
		}		
	}
	return res;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int X[n][m];
        for(int j = 0; j < m; j++){
            X[0][j] = a[0][j];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j]){
                    X[i][j] = X[i-1][j] + 1;
                }
                else{
                    X[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, Histogram(X[i], m));
        }
        cout << ans << endl;
    }
}