#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1010;
int capacity[MAX_NODES][MAX_NODES];
int residual[MAX_NODES][MAX_NODES];
vector<int> adj[MAX_NODES];

bool bfs(int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(source);
    parent[source] = source;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (parent[v] == -1 && residual[u][v] > 0) {
                parent[v] = u;
                if (v == sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int fordFulkerson(int source, int sink, int n) {
    memcpy(residual, capacity, sizeof(capacity));
    vector<int> parent(n + 1);
    int maxFlow = 0;

    while (bfs(source, sink, parent)) {
        int flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= flow;
            residual[v][u] += flow;
        }

        maxFlow += flow;
    }

    return maxFlow;
}

void solve() {
    memset(capacity, 0, sizeof(capacity)); // Reset capacity matrix
    for (int i = 0; i < MAX_NODES; i++) adj[i].clear(); // Reset adjacency list

    int n;
    cin >> n;
    int src, desti;
    cin >> src >> desti;
    int m;
    cin >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        capacity[u][v] += w;
        capacity[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxBandwidth = fordFulkerson(src, desti, n);
    cout << " " << maxBandwidth << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1;
    cin >> t;

    while (t--) {
        cout << "Case " << c++ << ":";
        solve();
    }
}
