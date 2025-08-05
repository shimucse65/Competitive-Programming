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
int n,m;
vector <int> g[N];
int siz[N] , par[N];
void make () {
    for (int i=0 ;i<=n ;i++) par[i]=i , siz[i]=1;
}
int root (int n) {
    if (par[n]==n) return n ;
    return par[n]= root (par[n]);
}
void merge (int a ,int b) {
     a=root (a);
     b=root (b);
     if (a==b) return  ;
     if (siz[a]<siz[b]) swap (a,b);
     par [b]=a;
     siz[a]+=siz[b]; 
}
void solve() {
    cin >>n >>m ;
    make ();
    int cnt =0;
    for  (int i=0 ; i < m ;i++) {
        int u, v; cin >> u>> v;
        if (root (u) != root (v)) {
            merge (u, v);
        } else cnt ++;
    }
    cout <<cnt <<"\n";
    
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