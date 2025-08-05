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
    if ((n&1)&& n <11 ) {
        cout <<-1<<"\n" ; return ;
    }

    if (n%2==0) {
    int cur=1 ;
    for (int i=1 ;i<=n ;i++ ) {
        cout <<cur <<" " ;
        if (i%2==0) cur++ ;
    }
    cout <<"\n" ; return ;
    }

    if (n<27) {
        cout <<-1 <<"\n" ; return ;
    }
    cout <<1<<" "<<2<<" "<<2<<" "<<3<<" "<<3<<" "<<4<<" "<<4 <<" "<<5 <<" "<<5<<" ";
    cout <<1 <<" "<<6<<" "<<6 <<" "<<7<<" "<<7 <<" "<<8 <<" "<<8 <<" "<<9 <<" "<<9<<" ";
    cout <<10 <<" "<<10 <<" "<<11<<" "<<11<<" "<<12<<" "<<13 <<" "<<13 <<" "<<1<<" "<<12<<" ";
    n-=27 ;
    int cur=14 ;
    for (int i=1 ;i<=n/2 ;i++) {
        cout <<cur <<" "<<cur<<" " ;
        cur++ ;
    }
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