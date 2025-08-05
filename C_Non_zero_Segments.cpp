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
const int inf = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int  n ;cin>>n ;
    int a[n] ;
    for (int i=0;i<n;i++) cin>>a[i] ;

    int pf[n] ; pf[0]= a[0] ;
   
    set <int>st ; st.insert (0) ; st.insert (a[0]) ;

    int cnt=0 ;

    for (int i=1 ;i<n;i++) {
        pf[i]= pf[i-1]+ a[i] ;
        if (!st.count (pf[i])) st.insert (pf[i]) ;
        else {
            cnt++ ;
            int notun= inf + pf[i-1] ;
            st.insert (notun) ;
            pf[i]= notun+ a[i] ;
            st.insert (pf[i]) ;
        }
        //for (auto it :st) cerr <<it <<" " ; cerr <<"\n" ;
    }
   // for (int i=0;i<n;i++) cerr <<pf[i] <<"\n" ;
    cout <<cnt <<"\n" ;
    
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