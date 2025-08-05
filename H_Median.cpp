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
const int N = 1e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int find (vector <int>&v) {
    sort (v.begin () ,v.end ());
    int n= v.size () ;
    if (n&1) return v[n/2] ;
    else return v[n/2-1] ;
}
void solve() {
    int n ,k;cin>>n>>k;
    vector <int>v ;
    int f=0 ;
    for (int i=0 ;i<n;i++) {
        int x ;cin>>x ;
        v.push_back (x) ;
        if (x==k) f=1 ;
    }
    int cnt=0 ;
    if (f==0) v.push_back (k) ,cnt++ ;
    
    while (1) {
        if (find (v)==k) break ;
        else {
            if (find (v) < k) v.push_back (N) ;
            else if (find (v)>k) v.push_back (1) ;
            cnt++ ;

        }
    }
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