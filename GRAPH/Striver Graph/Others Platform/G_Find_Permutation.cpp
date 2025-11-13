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
vector <int>g[N] ;
int in[N] ;
void solve() {
    int n ,m ;cin>>n>>m ;
    for (int i=0 ;i<m ;i++) {
        int x,y ;cin>>x>>y ;
        g[x].push_back (y) ;
        in[y]++ ;
    }
    queue <int>q ;
    for (int i=1 ;i<=n ;i++) {
        if (in[i]==0) q.push (i);
    }
    vector <int>ord ;
    while (!q.empty ()) {

        if (q.size () >1) {
            cout <<"No\n" ; return ;
        }
         int cur= q.front () ; q.pop () ;
         ord.push_back (cur);
         for (auto it :g[cur]) {
            in[it]-- ;
            if (in[it]==0) q.push(it);
        }

    }
    int cur=1 ;
    vector <int>v (n+1) ;
    for (auto it :ord) {
        v[it]= cur ; cur++ ;
    }
    for (int i=1 ;i<=n;i++) {
        if (v[i]==0) v[i]= cur++ ;
    }
    if (ord.size ()!=n) {
        cout <<"No\n" ; return ;
    }
    cout <<"Yes\n" ;
    for (int i=1;i<=n ;i++) cout <<v[i] <<" " ; cout <<"\n" ;

    
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