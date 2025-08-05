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

int multiple (int l ,int r ,int x) {
    int f= (l%x==0 ?l :l+ (x-l%x)) ;
    int last= r- (r%x) ;
    return  (last-f )/x+1 ;
}
void solve() {
    int l,r,k;cin>>l>>r>>k ;
    int tot= r/k ;
    if (tot-l <0) {
        cout <<0<<"\n" ; return ;
    }
    cout << (tot-l)+1 <<"\n" ;
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