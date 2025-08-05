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

int f (int a ,int n) {

    return( n*(2*a+ (n-1)*2))/2 ;
}
void solve() {

    int l,r ;cin>>l>>r ;
    int fe ,le ;
    if (l%2==0) fe=l ;
    else fe=l+1 ;
    if (r%2==0) le=r ;
    else le=r-1 ;
    int n =( (le-fe)/2 )+1 ;
    cout << f (fe,n)<<"\n" ;
    
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