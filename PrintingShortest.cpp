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
vector <pii >g[N] ;
vector <int>v ;
int par[N] ;
int n , m ;

 int  dij () {
    vector <int>dist (n+1 , inf) ;
    set <pii>st ;
    st.insert ({0,1}) ;// wt ,node  
    dist[1]=0; 
    par[1]=-1 ;

    while (!st.empty ()) {
        auto node= * st.begin () ; 
        st.erase (st.begin ()) ;
        int d1= node.ff , ch= node.ss ;

        for (auto it :g[ch]) {
            int v=it.ff , d2= it.ss ;
           
            if (d1+ d2 < dist[v]) {
                dist[v]= d1+d2 ;
                 par[v]=ch ;
                st.insert ({ dist[v] , v}) ;
            }
        }
    }
   
    int cur=n ;
    while (cur !=-1) {
        v.push_back (cur) ;
        cur= par[cur] ;
    }
     return dist[n] ;

}

void solve() {
    cin>>n>>m ;
    for (int i=0 ;i<m ;i++) {
        int u,v,wt ;cin>>u>>v>>wt ;
        g[u].push_back ({v,wt}) ;  //node , weight
        g[v].push_back ({u, wt}) ;
    }
     int x= dij () ;
     cout <<x <<"\n" ;
    
    for (auto it :v) cout <<it<<" " ; cout <<"\n" ;
    
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