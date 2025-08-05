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

    int n; cin >>n;
    int a[n];
    for (int i=0;i<n ;i++) cin >>a[i];
    int i,j;

    if (n%2==0) {
        i= n/2 -1 ; j= n/2;
    } else {
        i= n/2 -1 ; j= n/2 +1 ;
    }
    int dif=0;
    int cnt=0;
    int cur=0;
   
    while (i >= 0 &&  j < n) {
        a[i] += cur;
        if (a[i] > a[j]) {
            cout << -1 <<"\n"; return;
        }
         dif = a[j]- a[i];
         i-- ; j++;
         cnt+= dif;
         cur += dif;
    }
    cout << cnt <<"\n";
    
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