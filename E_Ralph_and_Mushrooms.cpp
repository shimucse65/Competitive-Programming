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
const int N = 1e6 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <pii > g[N], rev[N] , cond[N];
vector <int>order ,comp ;
int vis[N];
int sum[N] ,ind[N] , qsum[N] , fval[N];
vector <int>val ,tmp;
int cnt;
int dp[N];

void pre () {
    for (int i = 1; i < N; i++) {
        qsum[i]= qsum[i-1] + i;
        sum[i]=sum[i-1]+ qsum[i];
        tmp.push_back (qsum[i]);
    }
}

int b_search (int x) {
    if (x==0) return 0;
    int id= upper_bound (tmp.begin () ,tmp.end (),x)-tmp.begin ();
    int ans=( id+1)* x - sum[id];
    return ans;
}

void dfs (int u) {
    vis[u]=1;
    for (auto it :g[u]) {
        if (!vis[it.ff]) {
            dfs (it.ff );
        }
    }
    order.push_back (u);
}

void dfs2 (int u) {
    vis[u]=1;
    comp.push_back (u);
    for (auto it :rev[u]) {
        if (!vis[it.ff]) dfs2 (it.ff);
    }
}

int dfs3 (int u) {
    if (dp[u]!=-1) return dp[u];
    int res=0;
    for (auto it : cond[u]) {
        if (!vis[it.ff]) {
            res = max (res , it.ss+dfs3 (it.ff));
        }
    }
    res += fval[u];
    return dp[u]= res;
}

void solve() {

    int n,m;cin>>n>>m;
    for (int i=0 ;i<m ;i++) {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back  ({v,w});
        rev[v].push_back ({u,w});
    }

    for (int i=1 ;i<=n ;i++) if (!vis[i]) dfs (i);    
    reverse (order.begin () ,order.end ());
    for (int i=1 ;i<=n ;i++) vis[i]=0;

    for (auto it :order) {
        if (vis[it]) continue;
        comp.clear ();
        val.clear ();
        cnt++ ;
        dfs2 (it);
        for (auto ii :comp) ind[ii]= cnt;
        for (auto ii:comp) {
            for (auto jj :g[ii]) {
                if (ind[jj.ff]==cnt) val.push_back (jj.ss);
            }
        }
        for (auto kk : val) fval[cnt] += b_search (kk);
    }
    for (int i=1 ;i<=n ;i++) {
        for (auto it :g[i]) {
            if (ind[i] != ind[it.ff]) {
                cond[ind[i]].push_back ({ind[it.ff] ,it.ss});
            }
        }
    }
    memset (dp ,-1 ,sizeof dp);
    for(int i=1 ;i<=n;i++) vis[i]=0;
    int st ;cin>>st;
    st=ind[st];
    cout << dfs3 (st);    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre ();

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

