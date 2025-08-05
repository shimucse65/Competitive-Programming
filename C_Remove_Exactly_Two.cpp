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
vector < int> g[N];
int degree[N] ;

void reset (int n) {
    for (int i=1 ;i<=n ;i++) {
        g[i].clear () ;
        degree[i]=0;
    }
}
void solve() {
    int n; cin >>n ;
    reset (n);

    for (int i=0 ; i< n-1 ;i++) {
        int u,v;cin>>u>>v ;
        g[u].push_back (v);
        g[v].push_back (u);
        degree[u]++ ; degree[v]++;
    }

    multiset <int> st ;
    for (int i=1 ;i<=n ;i++) st.insert (degree[i]);

    //for (auto it :st) cerr << it <<" " ; cerr <<"\n";

    int mx =- inf ;
     for (int i=1 ; i<=n ;i++) {
        int ans= degree[i] - 1;
      //  cerr << ans <<" ";
        st.erase (st.find (degree[i]));
        for (auto it : g[i]) {
            st.erase (st.find (degree[it]));
            st.insert (degree[it] - 1);
        } 
        ans += *st.rbegin ();
        mx= max (mx , ans);

        
        for (auto it :g[i]) {
            st.erase (st.find (degree[it] - 1));
            st.insert (degree[it] );
        }
        st.insert (degree[i]);
     }
    cout << mx <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}