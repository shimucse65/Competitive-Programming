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
int in[N]  ,out[N];
void reset () {
    for (int i=0 ;i<1000 ;i++) g[i].clear () ;    
}
void solve() {

    int n,m ;cin>>n>>m ;
   
    vector <int>ans ;
    set <pii >st ;
    for (int i=0 ;i<m ;i++) {
        int x ,y ;cin>>x>>y ;
        g[x].push_back (y) ;
        in [y]++ ;    
    }
   
    priority_queue <int ,vector <int> , greater <int> >pq ;

    for (int i=1 ;i<=n ;i++) {
        if (in[i]==0) pq.push (i) ;
    }
    while (!pq.empty ()) {
        int cur= pq.top () ; pq.pop () ;
        ans.push_back (cur) ;

        for (auto it :g[cur]) {
            in[it]-- ;
            if (in[it]==0) pq.push(it) ;
        }
    }
    int cur=1 ;
    //for (auto it :ans) cerr <<it <<" " ; cerr <<"\n" ;
    if (ans.size () !=n) {
        cout <<"No\n" ; return ;
    }
    vector <int>v (n);
     for (auto it :ans) {
        v[it]= cur ; cur++ ;
       // cerr << it <<" " <<v[it] <<" " ; cerr <<"\n" ;
     }
     
     cout <<"Yes\n" ;
     for (int i=1 ; i<=n ;i++) cout <<v[i] <<" " ; cout <<"\n" ;
     reset () ;
     ans.clear () ;
    
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