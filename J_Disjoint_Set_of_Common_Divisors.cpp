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

bool isprime (int n) {
    if (n <2) return false ;
    for (int i=2 ;i*i<=n ;i++) {
        if (n%i==0) return false ;
    }
    return true ;
}

vector <int>divi (int n) {
    vector <int>res ;
    for (int i=1 ;i*i <=n ;i++) {
        if (n%i==0) {
            res.push_back (i) ;
            if (i*i!=n) {
                res.push_back (n/i) ;
            }
        }
    }
    return res ;
}
void solve() {
    int n,m ;cin>>n>>m ;
    vector <int>aa= divi (n) ;
    vector <int>bb= divi (m );

   map <int,int>mp ;
   for (auto it :aa) {
    mp[it]++ ;
   }
   for (auto it :bb) {
    mp[it]++ ;
   }
   vector <int>cc ;
   for (auto it :mp) {
    if (it.ss==2) {
        cc.push_back (it.ff) ;
    }
   }
    //for (auto it :cc) cerr <<it <<" " ; cerr <<"\n" ;
    int  cnt=0 ;
    for (auto it :cc) {
        if (it==1 || isprime (it)) cnt++ ;
    }
   cout<< cnt <<"\n" ; 
    
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