#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std;
const int inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> g(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, -x, -y);
    }
    
    vector<pii> ans(n + 1, {inf, inf});
    ans[1] = {0, 0};
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        auto [cx, cy] = ans[cur];
        
        for (auto [next, dx, dy] : g[cur]) {
            if (ans[next].ff == inf) {
                ans[next] = {cx + dx, cy + dy};
                q.push(next);
            } else if (ans[next] != make_pair(cx + dx, cy + dy)) {
                ans[next] = {-inf, inf};
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (ans[i].ff == inf || ans[i].ff == -inf) 
            cout << "undecidable" << endl;
        else 
            cout << ans[i].ff << " " << ans[i].ss << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
