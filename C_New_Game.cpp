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
    int n,k;cin >>n>>k;
    int a[n];
    map <int,int>mp;
    for (int i=0 ;i<n ;i++) {
        cin >> a[i] ; mp[a[i]]++;
    }
    
    sort (a, a+n) ;
    vector < pii > v;
    for (auto it :mp) v.push_back ({it.ff , it.ss});

    int ans = -inf ;
    int sm = 0 ;
    int cnt = 0 ,pv = a[0] - 1;

    for (int i = 0 ; i < v.size() ;i++){
        if (v[i].ff - pv != 1) {
            ans = max (sm ,ans);
            sm = v[i].ss; cnt = 1;
        } else if (cnt >= k) {  
            sm += v[i].ss; 
            sm -= v[i-k].ss;    
        } else {
            sm += v[i].ss;
            cnt ++;
        }
        ans = max (ans ,sm);
        pv = v[i].ff;
    }
    ans = max (ans , sm);
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