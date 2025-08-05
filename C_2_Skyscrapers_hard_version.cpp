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
int pf[N] , suf[N] ;

void solve() {

    int n ;cin>>n ;
   
    int a[n+1] ;
    for (int i=1 ;i<=n ;i++) cin>>a[i] , cout <<a[i] <<" " ;
    for (int i=1 ;i<=n ;i++) cout <<a[i] <<" " ; cout <<"\n" ;

   // stack <int>st ; st.push (0) ;
    

    // for (int i=1 ;i<=n ;i++) {
    //     while (a[st.top ()] >= a[i]) st.pop () ;
    //     pf[i]= pf[st.top()]+ (a[i]* (i-st.top ())) ;
    //     st.push (i) ;
    // }

    // while (st.size ()) st.pop () ;
    // st.push (n+1) ;
    // for (int i=n ;i>=1 ;i--) {
    //     while (a[st.top()]>=a[i]) st.pop () ;
    //     suf[i] = suf[st.top ()]+ (a[i]* (st.top ()-i)) ;
    //     st.push (i) ;
    // }

    // int mx_id=0 ,mx=0 ;

    // for (int i=1 ;i<=n;i++) {
    //     int cur= pf[i]+ suf[i]- a[i] ;
    //     if (cur >mx) {
    //         mx= cur ;
    //         mx_id= i ;
    //     }
    // }

    // for (int i=mx_id-1 ;i>=1 ;i--) {
    //     a[i]= min (a[i] ,a[i+1]) ;
    // }

    // for (int i=mx_id+1 ; i<=n ;i++) {
    //     a[i]= min (a[i] , a[i-1]) ;
    // }

    for (int i=1 ;i<=n ;i++) cout <<a[i] <<" " ; cout <<"\n" ;
    
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