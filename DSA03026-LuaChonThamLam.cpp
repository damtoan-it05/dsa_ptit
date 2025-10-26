#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve1(int N, int S){
    int Be[N+1];
    --S;
    for(int i = N; i >= 1; i--){
        for(int j = 9; j >= 0; j--){
            if((S - j) >= 0){
                Be[i] = j;
                S -= j;
                break;
            }
            else{
                Be[i] = 0;
            }
        }
    }
    Be[1] += 1;
    for(int i = 1; i <= N; i++){
        cout << Be[i];
    }
    cout << " ";
}

void solve2(int N, int S){
    int Lon[N+1];
    for(int i = 1; i <= N; i++){
        for(int j = 9; j >= 0; j--){
            if((S - j) >= 0){
                Lon[i] = j;
                S -= j;
                break;
            }
            else{
                Lon[i] = 0;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << Lon[i];
    }
}

int main(){
    int N, S;
    cin >> N >> S;
    if(((S == 0) and (N != 1)) or (S > (9 * N))){
        cout << "-1 -1" << endl;
        return 0;
    }
    solve1(N, S);
    solve2(N, S);
}