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
const int mod=7901;
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int fact[N] ;
void calc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = (fact[i - 1] * i) % mod;
}
void solve() {
    //cerr <<fact [1000] <<"\n" ;
    int n;cin>>n ;
    int a[n] ;
    map <int ,int>mp ;
    for (int i=0 ;i<n;i++) {
        cin>>a[i] ;
        mp[a[i]]++ ;
    }
    int ans=1 ;
    for (auto it :mp) {
        int x= it.ss ;
        int y= fact[x] ;
        ans= (ans*y)% mod ;
    }
    cout <<ans <<"\n" ;

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc () ;
    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}