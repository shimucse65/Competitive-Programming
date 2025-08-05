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

    // int n ; cin >> n;
    // int cnt=0;

    // if (n==0 || n==1) {
    //     cout <<  n + 1 <<"\n" ; return ;
    // }
    // n-=3 ;
    // int cur = n/15 ;
    // cur ++ ;
    // cnt += cur*3 ;

    //cerr << cnt <<"\n";

    // n += 3 ;
   
    // if ( n % 15 == 0) {
    //     cnt ++ ;
    // } 
    // if ( (n-1) % 15 == 0) {
    //     cnt += 2;
    // } 
    // else if (( n - 2 )% 15 == 0) {
    //     cnt += 3 ;
    // } 

    // cout << cnt <<"\n";
    int n;
    cin >> n;

    int cnt = (n / 15) * 3; 

   
    for (int i = (n / 15) * 15; i <= n; i++) {
        if (i % 3 == i % 5) cnt++;
    }

    cout << cnt << "\n";
    
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