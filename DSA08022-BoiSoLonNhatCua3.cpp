#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

/*
- Ý tưởng: Số dư của (n/3) = Số dư của ((Tổng các chữ số trong n)/3)
+ Tìm tổng chữ số trong mảng ban đầu là sum
+ TH1: Nếu (sum % 3 == 0) => Tất cả các chữ số đều có thể dùng để tạo số lớn nhất chia hết cho 3
+ TH2: Nếu (sum % 3 == 1) => Cần xóa 1 chữ số chia 3 dư 1. 
- Nếu không có chữ số chia 3 dư 1 thì cần xóa 2 chữ số chia 3 dư 2. 
- Nếu không có 2 chữ số chia 3 dư 2 thì không thể tạo đc kêt quả
+ TH3: Nếu (sum % 3 == 2) => Cần xóa 1 chữ số chia 3 dư 2. 
- Nếu không có chữ số chia 3 dư 2 thì cần xóa 2 chữ số chia 3 dư 1. 
- Nếu không có 2 chữ số chia 3 dư 1 thì không thể tạo đc kêt quả
*/

void Solve(int a[], int n){
    int sum = 0;
    vector<int> res;
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(a[i] % 3 == 0){
            res.push_back(a[i]);
        }
        else if(a[i] % 3 == 1){
            pq1.push(a[i]);
        }
        else{
            pq2.push(a[i]);
        }
    }
    if(sum % 3 == 0){
        while(!pq1.empty()){
            res.push_back(pq1.top()); pq1.pop();
        }
        while(!pq2.empty()){
            res.push_back(pq2.top()); pq2.pop();
        }
    }
    else if(sum % 3 == 1){
        if(!pq1.empty()){
            pq1.pop();
            while(!pq1.empty()){
                res.push_back(pq1.top()); pq1.pop();
            }
            while(!pq2.empty()){
                res.push_back(pq2.top()); pq2.pop();
            }
        }
        else{
            if(pq2.size() < 2){
                cout << "-1" << endl;
                return;
            }
            else{
                pq2.pop(); pq2.pop();
                while(!pq2.empty()){
                    res.push_back(pq2.top()); pq2.pop();
                }
            }
        }
    }
    else{
        if(!pq2.empty()){
            pq2.pop();
            while(!pq1.empty()){
                res.push_back(pq1.top()); pq1.pop();
            }
            while(!pq2.empty()){
                res.push_back(pq2.top()); pq2.pop();
            }
        }
        else{
            if(pq1.size() < 2){
                cout << "-1" << endl;
                return;
            }
            else{
                pq1.pop(); pq1.pop();
                while(!pq1.empty()){
                    res.push_back(pq1.top()); pq1.pop();
                }
            }
        }
    }
    if(res.size() == 0){
        cout << "-1" << endl;
        return;
    }
    sort(begin(res), end(res), greater<int>());
    string s = "";
    for(auto x : res){
        s += (x + '0');
    }
    while((s.size() > 1) and (s[0] == '0')){
        s.erase(0, 1);
    }
    cout << s << endl;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        int a[n];
        for(auto &x : a){
            cin >> x;
        }
        Solve(a, n);
    }
}