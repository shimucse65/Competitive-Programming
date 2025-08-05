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

int Mex(set<int> &s) {
    int mex = 1;
    while (s.count(mex)) {
        mex++;
    }
    return mex;
}

void solve() {
    int n,k;cin>>n>>k ;
    int a[n];
    int on=0;
    set <int>st ;
    for (int i=0;i<n;i++) {
        cin>>a[i] ;
        if (a[i]==1) on++ ;      
    }
    for (int i=1 ; i<n ;i+=2) st.insert (a[i]);
   
     if (k==n) {
        cout <<Mex (st) <<"\n"; return;
    }
    int ind=0 ;
    for (int i=0 ;i<n ;i++ ) {
        if (a[i] !=1) {
            ind=i ; break;
        }
    }
  
    if (n-1-ind >= k-2) {
        cout <<1 <<"\n"; return ;
    }
    cout <<2<<"\n";
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