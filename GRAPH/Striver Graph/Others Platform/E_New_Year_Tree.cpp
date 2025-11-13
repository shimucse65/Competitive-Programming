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
const int N = 4e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define lc (ind <<1) 
#define rc (ind <<1 |1)
int seg[4*N] ;
int a[N] ;
vector <int>g[N] ;
int st[N] , en[N] , lz[4*N] ;
int timer=0 ;
int n ,q ;

void Propagate (int ind , int lo ,int hi) {
    if (lz[ind]==0) return ;
    seg[ind]= lz[ind] ;
    if (lo !=hi) {
        lz[lc]= lz[ind] ;
        lz[rc]= lz[ind];
    }
    lz[ind]=0;
}


void update (int ind , int lo , int hi ,int l ,int r , int val) {
    Propagate (ind , lo ,hi) ;

    if (hi < l || r <lo) return ;
    if (l <= lo && hi <=r) {
        lz[ind]=val ;
       Propagate (ind , lo ,hi) ;
       return ;
    }
    int mid = (lo+hi)/2 ;
    update (lc , lo ,mid ,l,r,val) ;
    update (rc ,mid+1 , hi , l,r,val) ;
    seg[ind]= seg[lc] | seg[rc] ;

}
int query (int ind , int lo , int hi , int l ,int r) {
    Propagate (ind ,lo,hi);
    if (hi <l || r<lo) return 0ll ;
    if (l<=lo && hi <=r) {
        return seg[ind];
    }
    int mid = (lo+hi)/2 ;
    return query (lc ,lo ,mid ,l,r) | query (rc ,mid+1,hi ,l,r);
}
void dfs_flat (int node , int p) {
    st[node]=++timer ;
    for (auto it :g[node]) {
        if (it==p) continue ;
        dfs_flat (it , node) ;
    }
    en[node]= timer ;

}
void dfs_col (int node , int p) {
    update (1,1,n ,st[node] ,en[node],(1ll<<a[node]));
    for (auto it :g[node]) {
        if (it==p) continue ;
        dfs_col (it ,node);
    }
}
void solve() {
    cin>>n>>q ;
    for (int i=1 ;i<=n ;i++)cin>>a[i] ;
    for (int i=0;i<n-1;i++){
        int x,y;cin>>x>>y ;
        g[x].push_back (y);
        g[y].push_back (x) ;
    }
    dfs_flat (1,-1) ;
    dfs_col (1,-1) ;

    // for(int i = 1; i <= n; i++) {
    //     update (1,1,n ,st[i] ,st[i],(1ll<<a[i]));
    // }

     //for(int i = 1; i <= n; i++) cerr<<st[i]<<" "<<en[i]<<endl;

    while (q--) {
        int ty; cin>>ty;
        if (ty == 1) {
            int node, col; cin>>node>>col;
            update (1, 1, n, st[node], en[node], (1ll << col));
        } else {
            int node; cin>>node;
            int tot = query(1, 1, n, st[node], en[node]);
          //  cerr <<tot <<"\n" ;
            cout << __builtin_popcountll(tot) <<"\n" ;
        }
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