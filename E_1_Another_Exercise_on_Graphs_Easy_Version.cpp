
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> wt;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        wt.push_back(w);
    }

    sort(wt.begin(), wt.end());
    vector<vector<vector<int>>> qu(n + 1);
    vector<int> res(q + 1, 1e9);

    for (int i = 1; i <= q; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        if (u > v) swap(u, v);
        qu[u].push_back({v, k, i});
    }

    for (int start = 1; start <= n; start++) {
        for (int weight : wt) {
            vector<int> dist(n + 1, 1e9);
            dist[start] = 0;

            deque<int> dq;
            dq.push_back(start);
            while (!dq.empty()) {
                int cur = dq.front();
                dq.pop_front();
                for (auto& edge : g[cur]) {
                    int ch = edge.first;
                    int edgeWeight = edge.second;
                    int extraCost = (edgeWeight > weight) ? 1 : 0;

                    if (dist[cur] + extraCost < dist[ch]) {
                        dist[ch] = dist[cur] + extraCost;
                        if (extraCost == 0) {
                            dq.push_front(ch);
                        } else {
                            dq.push_back(ch);
                        }
                    }
                }
            }

            for (auto& query : qu[start]) {
                int tg = query[0];
                int mxedge = query[1];
                int ind = query[2];

                if (dist[tg] < mxedge) {
                    res[ind] = min(res[ind], weight);
                }
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
