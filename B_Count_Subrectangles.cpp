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

    int n ,m ,k ;cin>>n >>m >>k ;
    vector <int>a (n) , b(m) , rr (n) ,cc (n) ;
    for (int i=0 ;i<n;i++) cin>>a[i] ;
    for (int i=0 ;i<m;i++) cin>> b[i] ;

    int cnt=0 ;
    for (int i=0 ;i <n ;i++) {
        if (a[i]==1) cnt++ ;
        else {
            rr.push_back (cnt) ; cnt=0 ;
        }
    }
    rr.push_back (cnt) ;
    cnt=0 ;
    
    for (int i=0 ;i<m ;i++) {
        if (b[i]==1) cnt++ ;
        else {
            cc.push_back (cnt) ; cnt=0 ;
        }
    }
    cc.push_back (cnt) ;

    vector <int>div ;
    for (int i=1 ;i*i <= k ;i++) {
        if (k%i==0) {
            div.push_back (i) ;
            if (i*i !=k) {
                div.push_back (k/i) ;
            }
        }
    }

    int ans=0 ;

    for (auto it :div) {
        int x= it , y= k/it , aa=0 ,bb=0 ;
        for (int j=0 ;j< cc.size () ;j++) {
            aa+= max (cc[j]-y+1, 0ll) ;
        } 
        for (int j=0 ;j<rr.size () ;j++) {
            bb+= max (rr[j]-x+1,0ll) ;
        }
        ans+= (aa*bb) ;
    }
    cout << ans <<"\n" ;
    
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