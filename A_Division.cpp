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

vector <int> primeFactor (int n) {
    vector <int>res ;
    if (n%2==0) {
        res.push_back (2) ; 
        while (n%2==0) n/=2 ;
    }
    for (int i=3 ;i*i <=n ;i+=2) {
        if (n%i==0) {
            res.push_back (i) ;
            while (n%i==0) n/=i ;
        }
    }
    if (n>1) res.push_back (n) ;
    return res ;
}

void solve() {
    int n ,m;cin>>n>>m ;
    int tmp= n ;
    if (n%m!=0) {
        cout << n <<"\n" ; return ;
    }
    vector <int>v= primeFactor(m) ;
    int res=-1 ;
    for (auto it :v) {
      while (n%it==0) {
        n/=it ;
        if (n%m!=0) {
            res= max (res ,n) ; break;
        }
      }
      n=tmp ;
    }
    cout <<res <<"\n" ;
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