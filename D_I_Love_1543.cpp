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
int n,m ;
vector <string >v (n) ;

int  f (int i) {
    int ans=0 ;
    string s="" ;
    for (int j=i ;j<m-i ;j++) s+=v[i][j] ;
    for (int row=i+1 ;row<n-i ;row++) s+= v[row][m-i-1] ;
    for (int j=m-i-2 ;j>=i ;j--) s+= v[n-i-1][j] ;
    for (int row=n-i-2 ;row >=i+1 ;row--) s+= v[row][i] ;
    
    //for (int k=0 ;k< s.size() ;k++) ans+= (s.substr(k ,4)=="1543") ;
    int sz= s.size () ;
    for (int k=0 ;k<sz ;k++) {
         string tmp="" ;
         for (int j=k ;j<k+4 ;j++) tmp+=s[j%sz] ;
         if (tmp=="1543") ans++ ;
    }
    return ans ;
}

void solve() {
    cin>>n>>m ;
    v.resize (n) ;
    for (int i=0;i<n;i++) cin>>v[i] ;
    int ans=0 ;
    for (int i=0 ;i< min (n,m)/2 ;i++) ans+= f (i) ;
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