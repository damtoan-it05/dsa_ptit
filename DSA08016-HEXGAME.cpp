#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

// Quay tam ben trai theo chieu kim đong ho
void Change1(vector<int> &vt){
    vector<int> tmp = vt;
    vt[0] = tmp[3]; vt[1] = tmp[0]; vt[5] = tmp[1];
    vt[8] = tmp[5]; vt[7] = tmp[8]; vt[3] = tmp[7];
}

// Quay tam ben phai theo chieu kim đong ho
void Change2(vector<int> &vt){
    vector<int> tmp = vt;
    vt[1] = tmp[4]; vt[2] = tmp[1]; vt[6] = tmp[2];
    vt[9] = tmp[6]; vt[8] = tmp[9]; vt[4] = tmp[8];
}

// Quay tam ben trai nguoc chieu kim đong ho
void Change3(vector<int> &vt){
    vector<int> tmp = vt;
    vt[0] = tmp[1]; vt[1] = tmp[5]; vt[5] = tmp[8];
    vt[8] = tmp[7]; vt[7] = tmp[3]; vt[3] = tmp[0];
}

// Quay tam ben phai nguoc chieu kim đong ho
void Change4(vector<int> &vt){
    vector<int> tmp = vt;
    vt[1] = tmp[2]; vt[2] = tmp[6]; vt[6] = tmp[9];
    vt[9] = tmp[8]; vt[8] = tmp[4]; vt[4] = tmp[1];
}

int solve(vector<int> start, vector<int> target){
    int result = INT_MAX;
    map<vector<int>, int> mp;
    queue<pair<vector<int>, int>> Q1; // Dem so buoc cua trang thai khi quay xuoi
    Q1.push({start, 0});
    while(!Q1.empty()){
        auto it = Q1.front(); Q1.pop();
        vector<int> tmp1 = it.first; 
        Change1(tmp1);
        if(!mp[tmp1]){
            mp[tmp1] = it.second + 1;
            Q1.push({tmp1, it.second + 1});
        }
        vector<int> tmp2 = it.first; 
        Change2(tmp2);
        if(!mp[tmp2]){
            mp[tmp2] = it.second + 1;
            Q1.push({tmp2, it.second + 1});
        }        
        if((it.second + 1) > 14){
            break;
        }
    }
    queue<pair<vector<int>, int>> Q2; // Dem so buoc cua trang thai khi quay nguoc
    Q2.push({target, 0});
    while(!Q2.empty()){
        auto it = Q2.front(); Q2.pop();
        // Neu da co so buoc quay xuoi => So buoc can xoay = So buoc quay xuôi + So buoc quay nguoc
        if(mp[it.first]){
            result = min(result, mp[it.first] + it.second);
        }
        vector<int> tmp3 = it.first; 
        Change3(tmp3);
        Q2.push({tmp3, it.second + 1});
        vector<int> tmp4 = it.first; 
        Change4(tmp4);
        Q2.push({tmp4, it.second + 1});
        if((it.second + 1) > 14){
            break;
        }
    }
    return result;
}

int main(){
    int arr[10] = {1, 2, 3, 8, 0, 0, 4, 7, 6, 5};
    vector<int> target(arr, arr + 10);
    int TC;
    cin >> TC;
    while(TC--){
        vector<int> start;
        for(int i = 0; i < 10; i++){
            int x; cin >> x;
            start.push_back(x);
        }
        cout << solve(start, target) << endl;
    }
}