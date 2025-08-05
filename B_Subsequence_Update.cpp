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
    int l,r ;cin>>l>>r ;
    l-- ,r--;
    int k= r-l+1 ;
    int a[n];
    for (int i=0 ;i<n;i++) cin>>a[i];

    // vector < int> v , vv ,vvv;
    // for (int i=0 ; i<l ;i++) v.push_back (a[i]) ;
    // sort (v.begin () , v.end ());
    // // int sz1= v.size () ;
    // int pf[sz1] ;
    // pf[0]=  v[0] ;
    // for (int i=1 ;i< sz1 ;i++) pf[i]= pf[i-1]+ v[i];

    // for (int i= r+1 ; i < n ;i++) vv.push_back (a[i]);
    // sort (vv.begin () ,vv.end ());
    // int sz2= vv.size () ;
    // int pf2[sz2] ;
    // pf2[0]=  vv[0] ;
    // for (int i=1 ;i< sz2 ;i++) pf2[i]= pf2[i-1]+ vv[i];

    // for (int i=l ; i<=r ;i++) vvv.push_back (a[i]);
    // sort (vvv.begin () ,vvv.end ());

    vector < int> v,vv;
     for (int i=0 ; i <=r ;i++) v.push_back (a[i]);
     sort (v.begin () ,v.end ());
     int sm1=0 ;

     for (int i=0 ;i< k;i++) sm1+= v[i] ;

     int sm2=0;
     for (int i=l ; i<n ;i++) vv.push_back (a[i]);
     sort (vv.begin () ,vv.end ());
     for (int i=0 ;i<k ;i++) sm2+= vv[i] ;


     cout << min (sm1 ,sm2) <<"\n";

   
    
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