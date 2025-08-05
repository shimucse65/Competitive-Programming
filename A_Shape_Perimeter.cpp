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

void solve() {

    int n ,m ;cin>>n>>m ;
    vector < pii > v ;
    for (int i=0 ;i<n ;i++) {
        int x ,y ;cin >>x>>y ;
        v.push_back ({x,y});
    }

    int ans= m *n *4 ;

    int enx= v[0].ff+m , eny= v[0].ss+m ;
    int stx= v[0].ff + v[1].ff , sty= v[0].ss + v[1].ss;
    int  tmp =( (enx- stx ) + (eny - sty))*2 ;
    //cerr << tmp <<"\n";
   // ans-= tmp;

    for (int i=1 ;i < n ;i++) {
        enx = stx + m , eny= sty+m ;
        stx = stx + v[i].ff ,sty= sty+ v[i].ss ;
        tmp =( (enx- stx ) + (eny - sty))*2 ;
        //cerr << tmp <<"\n";
        ans-= tmp;
    }
   
    cout << ans <<"\n";
    
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