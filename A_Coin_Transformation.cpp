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

int big_mod (int a,int b)
  {
    int ans=1;
    while (b)
     {
        if (b&1) ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b=b>>1;
     }
     return ans;
  }

void solve() {
    int n ;cin>>n ;
    if (n <=3) {
        cout <<1 <<"\n" ; return ;
    }
    int cnt=1 ;
    while (n>3) {
        n/=4 ;
        cnt*=2;
    }
    
    cout << cnt<<"\n" ;
    
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