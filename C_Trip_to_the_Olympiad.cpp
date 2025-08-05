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
    int l,r;cin>>l>>r ;
    int a,b,c ;
    int ans=0;
    for (int i = 30; i >= 0; i--) {
        bool f1=0 ,f2=0;
        if (l & (1ll<<i)) f1=1 ;
        if (r& (1ll<<i))  f2=1;
        if (f1==f2) {
            ans+= f1* (1ll <<i);
        }  else {
            ans+= (1ll << i);
            a= ans;
            b=ans-1;
            break;
        }
    }
    for (int i=l ;i<=r ;i++) {
        if (i!=a && i!=b) {
            c=i; break;
        }
    }
    cout <<a <<" " <<b <<" " <<c <<"\n";
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