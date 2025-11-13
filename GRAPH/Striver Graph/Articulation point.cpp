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
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N];
int vis[N] ,low[N] ,tin[N];
int tm=0;
vector <int>ans;

void dfs (int node , int par) {
    tin[node]= low[node]= tm++ ;
    vis[node]=1;
    int ch=0;
    for (auto it :g[node]) {
        if (it==par) continue;
        if (vis[it]) {
            low[node]= min (low[node] , low[it]);
        } else {
            dfs (it ,node);
            low[node]= min (low[node] , low[it]);
            if (low[it] >= tin[node] && par!=-1) {
                ans.push_back (node);
            }
            ch++;
        }
    }
    if (ch > 1 && par!=-1) ans.push_back (node);
}
void solve() {
    int n,m;cin>>n>>m ;
    for (int i=0 ;i<m ;i++) {
        int x,y;cin>>x>>y;
        g[x].push_back (y);
        g[y].push_back (x);
    }

    for (int i=0;i<n ;i++) {
        if (!vis[i]) dfs(i);
    }

    for (auto it :ans) cout <<it <<" " ; cout <<"\n";   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}