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

    int n , k;cin>>n>>k ;
    string s;cin>>s ;
    vector <int> ans (n ,1) ;
    vector <int>v ;
    int i=0 ;
    while (s[i]=='0') i++ ;
     int pos= i ;
    for ( ;i<n;i++) {
        if (s[i]=='0') v.push_back (i) ;
    }
    //for (auto it :v) cout <<it <<" " ; cout <<"\n" ;

    for (int i=0 ;i<pos ;i++) {
        if (s[i]=='0') ans[i]=0 ;
    }
    
    int ex=-1 ;
    for (auto it :v) {
        int need=it-pos ;
        if (need <=k) { 
            ans[pos]=0 ;k-= need ; pos++ ;
        } else {
            ans[it-k]=0 ; ex=it ;break ;
        }
    }
    if (ex==-1) {
        for (auto it :ans ) cout <<it ; cout <<"\n" ; return ;
    }
    for (int i=0;i<= ex ;i++) cout <<ans[i] ;
    for (int i=ex+1 ;i <n ;i++) cout <<s[i] ; 
    cout <<"\n" ;
    
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