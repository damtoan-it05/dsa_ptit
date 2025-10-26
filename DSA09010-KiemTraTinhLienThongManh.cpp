#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

vector<int> vt[1005];
int in[1005], low[1005], onStack[1005];
stack<int> st;
int v, e, timer = 0,scc=0;

void tarjan(int u) {
	in[u] = low[u] = ++timer;
	st.push(u);
	onStack[u] = 1;
	for(int x : vt[u]) {
		if (in[x] == -1) {
			tarjan(x);
			low[u] = min(low[u], low[x]);
		} else if (onStack[x]) {
			low[u] = min(low[u], in[x]);
		}
	}

	if (low[u] == in[u]) {
		scc++;
    	int x;
        do {
            x = st.top(); st.pop();
            onStack[x] = 0;
        } while (x != u);
	}
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> v >> e;
		timer = 0,scc=0;
		for (int i = 1; i <= v; i++) {
            vt[i].clear(); 
        }
		for(int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			vt[x].push_back(y);
		}
		while (!st.empty()) st.pop();
        memset(in, -1, sizeof(in));
        memset(low, 0, sizeof(low));
        memset(onStack, 0, sizeof(onStack));
		for(int i = 1; i <= v; i++) {
			if (in[i] == -1) tarjan(i);
		}
		if(scc==1) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}