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
const int N = 5010;
const int M= 1e5+10;
const int inf = 1e18 + 10;
const long double eps= 1e-9+10 ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>cap ;
struct edge {int u,v,id ; long double wt ;} ;
edge ed[M];
int par[N] ;
bool by_w (edge a , edge b) {return a.wt < b.wt ;} 
bool by_id (edge a ,edge b) {return a.id < b.id ;}
int siz[N];

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

    int n,m,k;cin>>n>>m>>k;
    for (int i=1 ;i<=m ;i++) {
        ed[i].id=i;
        cin>> ed[i].u >> ed[i].v >>ed[i].wt;
        if (ed[i].u==1) cap.push_back (i) ;
     }

    long double  l= -1e5 , r= 1e5 ;
    int it=0 ;
    while ( it <80 ) {
        it++ ;
        long double mid= (l+r)/2 ;
        for (int ii=1 ;ii<=n ;ii++) par[ii]=ii ,siz[ii]=1 ;
        for(auto it :cap ) ed[it].wt += mid ;
        sort (ed+1 , ed+m+1 , by_w) ;
        int cnt=0 ;
        vector <int>ans ;
        for (int i = 1 ;i <= m ;i++) {
            if (root (ed[i].u)== root (ed[i].v)) continue ;
            merge (ed[i].u , ed[i].v);
            if (ed[i].u==1) cnt++ ;
        }
        sort (ed+1 ,ed+m+1, by_id);
        if (cnt >k) l= mid;
        else if (cnt <k) r= mid ;
        else {
            cout << ans.size () <<"\n" ;
            for (auto it :ans) cout << ed[it].id <<" " ; return ;
        }
      for(auto it :cap ) ed[it].wt -= mid ;
    
	}
    cout <<-1 <<"\n" ;
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