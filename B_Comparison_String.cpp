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
    int n; cin >> n;
    string s; cin >>s;
    int mx= -inf ;
    int cnt=0;
    for (int i=0 ;i<n ;i++) {
        if (s[i]=='<') cnt++ ;
        else {
            mx = max (mx , cnt) ; cnt=0;
        }
    }
    mx= max (mx , cnt);
    int cnt2=0 ;
    int mx2=-inf ;
    for (int i=0 ;i <n ;i++) {
        if (s[i]=='>') cnt2++ ;
        else {
            mx2= max (mx2 , cnt2);
            cnt2=0;
        }
    }
    mx2= max (mx2 , cnt2);
    cout << max (mx , mx2)+1 <<"\n";
    
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
