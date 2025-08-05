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
vector <pii>g[N] ;
int ans[N] ;

void solve() {
    int  n ;cin>>n ;
    map <int ,int>mp ;
    memset (ans ,-1 ,sizeof ans) ;
    for (int i=0;i<n-1 ;i++) {
        int u,v;cin>>u>>v ;
       
        g[u].push_back ({v,i}) ;
        g[v].push_back ({u,i}) ;
    }

    int who=0 ;
    for (int i=1 ;i<=n ;i++) {
        if (g[i].size ()>2) {
            who= i ;break;
        }
    }
   
    int cur =0 ;
    for (auto it :g[who]) {
        ans[it.ss]=cur ; cur++ ;
    }
    for (int i=0 ;i<n-1 ;i++) {
        if (ans[i]==-1) {
            ans[i]=cur ; cur++ ;
        }
    }

    for (int i=0;i<n-1;i++) cout<<ans[i]<<"\n" ;
    
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