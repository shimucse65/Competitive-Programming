#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int inf = 1e9 + 10;

vector<pair<int, int>> g[N];
bool vis[N];
vector<int> dis(N, inf);

void reset() {
    for (int i = 0; i < N; i++) {
        vis[i] = 0;
        g[i].clear();
    }
}

void dij(int src) {
    set<pair<int, int>> st; 
    st.insert({0, src});
    dis[src] = 0;

    while (!st.empty()) {
        auto node = *st.begin();
        int cur_dis = node.first;
        int v = node.second;
        st.erase(st.begin());

        for (auto child : g[v]) {
            int ch = child.first;
            int wt = child.second;
            if (dis[v] + wt < dis[ch]) {
                st.erase({dis[ch], ch}); 
                dis[ch] = dis[v] + wt;
                st.insert({dis[ch], ch}); 
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w}); 
    }

    dij(1); 

    for (int i = 1; i <= n; i++) {
        if (dis[i] == inf)
            cout << i << " " << "INF" << "\n"; 
        else
            cout << i << " " << dis[i] << "\n";
    }

    return 0;
}
