#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;

int n, k, ans = 0;
vector<int> g[N];
int vis[N], sub[N], cnt[N];
int mx=0 ;
void dfs(int node, int par) {
    sub[node] = 1;
    for (auto it : g[node]) {
        if (it == par || vis[it]) continue;
        dfs(it, node);
        sub[node] += sub[it];
    }
}

int find_centroid(int node, int par, int total) {
    for (auto it : g[node]) {
        if (it != par && !vis[it] && sub[it] > total / 2) {
            return find_centroid(it, node, total);
        }
    }
    return node;
}

void dfs2(int node, int par, int depth, bool flag) {
    
    if (depth > k) return; 
    if (flag) ans += cnt[k - depth];
    else cnt[depth]++;
    mx=max (mx ,depth) ;
    for (auto it : g[node]) {
        if (it == par || vis[it]) continue;
        dfs2(it, node, depth + 1, flag);
    }
}

void cd(int node) {
    
    dfs(1, -1);
    int centro = find_centroid(node, -1, sub[node]/2);
    
    vis[centro] = true;
    cnt[0] = 1; 
    mx=0 ;
    for (auto it : g[centro]) {
        if (!vis[it]) {
            dfs2(it, centro, 1, true);
            dfs2(it, centro, 1, false);
        }
    }
    

  fill(cnt, cnt+mx+10, 0);
   
    for (auto it : g[centro]) {
        if (!vis[it]) {
            cd(it);
        }
    }
}

void solve() { 
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
   
    cd(1);
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}
