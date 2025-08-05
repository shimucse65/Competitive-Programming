#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> weights;
        vector<vector<pair<int, int>>> graph(n + 1);
        // Read edges
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            weights.push_back(w);
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Sort weights in ascending order
        sort(weights.begin(), weights.end());
        // Read queries
        vector<vector<vector<int>>> queries(n + 1); // {b, k, index}
        vector<int> results(q + 1, 1e9 + 1);
        for (int i = 1; i <= q; i++) {
            int a, b, k;
            cin >> a >> b >> k;

            if (b < a) swap(a, b);
            queries[a].push_back({b, k, i});
        }

        // Process each node as a starting point
        for (int start = 1; start <= n; start++) {
            for (int weight : weights) {
                vector<int> dist(n + 1, 1e9);
                dist[start] = 0;

                deque<int> dq;
                dq.push_back(start);

                // Perform a modified BFS
                while (!dq.empty()) {
                    int current = dq.front();
                    dq.pop_front();

                    for (auto& edge : graph[current]) {
                        int neighbor = edge.first;
                        int edgeWeight = edge.second;
                        int extraCost = (edgeWeight > weight) ? 1 : 0;

                        if (dist[current] + extraCost < dist[neighbor]) {
                            dist[neighbor] = dist[current] + extraCost;
                            if (extraCost == 0) {
                                dq.push_front(neighbor);
                            } else {
                                dq.push_back(neighbor);
                            }
                        }
                    }
                }

                // Update query results
                for (auto& query : queries[start]) {
                    int target = query[0];
                    int maxEdges = query[1];
                    int queryIndex = query[2];

                    if (dist[target] < maxEdges) {
                        results[queryIndex] = min(results[queryIndex], weight);
                    }
                }
            }
        }

        // Output results
        for (int i = 1; i <= q; i++) {
            cout << results[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}