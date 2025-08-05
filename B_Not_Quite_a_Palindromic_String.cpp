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
    int n,k; cin >>n>>k;
    string s; cin >>s ;
    if (k==0) {
        int cnt0 = count (s.begin () , s.end () ,'0');
        int cnt1 = n- cnt0;
        if (cnt0== n/2 && cnt1== n/2) cout <<"YES\n";
        else cout <<"NO\n";
        return;
    }
    map <char , int >mp;
    for (auto it :s) mp[it]++;

    int xx= n-2*k ;
    xx/=2 ;
    if (mp['0'] < xx || mp['1'] <xx) {
        cout << "NO\n"; return;
    }
    int pp= mp['0']- xx;
    int qq= mp['1']- xx;
    
    if (pp % 2==0 && qq % 2 ==0 &&  (pp/2 + qq/2 ==k)) cout <<"YES\n";
    else cout <<"NO\n";

    
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
