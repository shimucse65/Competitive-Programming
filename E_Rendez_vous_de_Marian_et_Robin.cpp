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
int horse[N] ;
int n, m,h ;
vector <pii>g[N] ;

void reset (int n) {
    for (int i=0 ;i<=n ;i++) {
        g[i].clear () ;
        horse[i]=0 ;
    }
}
vector <int> dij (int s) {
    vector < vector <int> >dist (n+1 ,vector <int>(2,inf)); //node , flag 
    vector <vector <int> >vis (n+1 ,vector <int> (2,0)); //node , vis 

    set < pair <int , pii>>st ; //distance , {node ,flag} 
    st.insert ({0,{s,horse[s]}});
    dist[s][horse[s]]= 0 ;

    while (!st.empty()) {

        auto cur= *st.begin () ;
        st.erase (st.begin ()) ;
        int di= cur.ff , node= cur.ss.ff , f= cur.ss.ss ;
        if (vis[node][f]) continue ;
        vis[node][f]=1 ; 
    
        for (auto it :g[node]) {
            int v= it.ff , w= it.ss ;
            if (f) w/=2 ;
            int f1= f | horse[v] ;
            if (dist[node][f]+ w < dist[v][f1]) {
                dist[v][f1]= dist[node][f]+w ;
                st.insert ({dist[v][f1] ,{v,f1}});
            }
        }
    }
    vector <int>d (n+1 ,inf) ;
    for (int i=1 ;i<=n;i++) {
        d[i]= min (dist[i][0] , dist[i][1]);
    }
    return d ;
}

void solve() {
    cin>>n>>m>>h ;
    reset (n) ;
    for (int i=0 ;i<h;i++) {
        int x ;cin>>x ;
        horse[x]=1 ;
    }
    while (m--) {
        int u,v,w ;cin>>u>>v>>w ;
        g[u].push_back ({v,w});
        g[v].push_back ({u,w});
    }

    vector <int>d1= dij (1) ;
    vector <int>d2= dij (n) ;
    int ans=inf ;
    for (int i=1 ;i<=n;i++) {
        if (d1[i]<inf && d2[i]<inf) {
            ans= min (ans , max(d1[i], d2[i]));
        }
    }
    if (ans==inf) ans=-1 ;
    cout <<ans <<"\n" ;
    
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