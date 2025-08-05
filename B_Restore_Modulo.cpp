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
    int n ;cin>>n ;
    int a[n] ;
    for (int i=0;i<n;i++) cin>>a[i] ;
    set <int>st ;
    vector <int>dif ;
    int cnt=0 ;
    for (int i=1;i<n;i++) {
        dif.push_back (a[i]-a[i-1]) ;
        st.insert (a[i]-a[i-1]) ;
        if (a[i]==a[0]) cnt++ ;
    }
    if (cnt==n-1) {
        cout <<0<<"\n" ; return ;
    }
    if (st.size ()>2) {
        cout <<-1 <<"\n" ; return ;
    }
    for (auto it :dif) {
        if (it==0) {
            cout <<-1 <<"\n" ; return ;
        }
    }
    int pos=0 ,neg=0 ,cnt1=0 ,cnt2=0 ;
    for (auto it :st) {
        if (it>0) {
            pos=it ; cnt1++ ; 
        }
        else {
            neg= it ; cnt2++ ;
        }
     }
     if (!cnt1 ||!cnt2) {
        cout <<-1 <<"\n" ; return ;
     }
    int d=0 ;
    if (cnt1 && cnt2) d=pos ;
    else if (cnt1 && !cnt2 ) d=pos ;
    else d= neg ;

    int b[n] ;
    b[0]= a[0] ;
    for (int i=1 ;i<n;i++) {
        b[i]= a[i-1]+d ;
    }
    vector <int>v ;

    for (int i=0 ;i<n;i++) {
        if (a[i]!=b[i]) {
            v.push_back (b[i]-a[i]) ;
        }
    }
    int gg=0 ;
    for (auto it :v) {
        gg= __gcd (gg,it) ;
    }
    int notun [n] ; notun[0]=a[0] ;
    for (int i=1 ;i<n;i++) {
        notun[i]=( notun[i-1]+d )%gg ;
    }

    for (int i=0;i<n;i++) {
        if (a[i]!= notun[i]) {
            cout <<-1<<"\n" ; return ;
        }
    }
   
    cout <<gg <<" "<<d <<"\n" ;
    
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