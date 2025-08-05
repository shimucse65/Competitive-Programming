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
const int N = 3e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,k;
int a[N];
string s;

bool check (int x) {
    int cnt = 0 ;
    int pv = 'R';
    for (int i = 0; i < n ;i++) {
        if (a[i] > x) {
            if (s[i] == 'B' && pv != 'B') cnt ++ ;
            pv = s[i];
        }
    }
    return cnt <= k;
}
void solve() {
    cin >> n>>k;
    cin >>s;
    for (int i=0 ;i<n ;i++) cin >> a[i];

    int l=0 , r = 1e9 + 10;
    int ans = 0 ;
    while (l <= r) {
        int mid = l + (r-l)/2 ;
        if (check (mid)) {
            ans = mid ;
            r = mid -1 ;
        } else l = mid + 1;
    }
    cout << ans <<"\n";   
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