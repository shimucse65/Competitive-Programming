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
void solve() {
    int n,m,q; cin >>n >>m>>q;
    for (int i=0 ;i<n ;i++) {
        int u,v; cin >>u>>v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    vector <int > a(n+1,0);
    vector <int> vv;
    while (q--) {
        int ty; cin >>ty;
       // cerr << ty <<"\n";
        int cur=1;
        if (ty==1) {
            int u ; cin >>u ;
            a[u]=1;
            vv.push_back (u);
        }
        else if (ty==2) {
            int tt; cin >>tt;
            for (auto it :vv) {
                //cerr << it <<"\n";
                    int uu= it;
                    for (auto iit: g[uu]) {
                       // cerr << iit <<" ";
                        a[iit]=1;
                    } 
                
            }
        }
         else if (ty==3) {
            int u; cin >>u;
            if (a[u]==1) cout <<"YES\n";
            else cout <<"NO\n";
        }
        //for (auto it:a) cerr << it <<" "; cerr<<"\n";
    }

    
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