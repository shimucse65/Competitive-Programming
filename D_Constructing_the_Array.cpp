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

struct cmp {
    bool operator () (const pii a ,const pii b) const {
        int lna= a.ss- a.ff + 1 , lnb= b.ss- b.ff+1;
        if (lna==lnb) return a.ff < b.ff;
        return lna > lnb;
    }
};
void solve() {
    int n;cin>>n;
    set < pii ,cmp >st;
    st.insert ({1,n});
    int ans[n+1];
    int tmp=1;
    while (st.size () >0) {
        auto cur= *st.begin(); st.erase (cur);
        int l= cur.ff , r= cur.ss;
        int mid= (l+r)/2;
        ans[mid] = tmp++;

        if (l < mid) st.insert ({l ,mid-1});
        if (mid <r) st.insert ({mid+1 ,r});       
    } 

    for (int i=1 ;i<=n ;i++) cout <<ans[i] <<" "; 
    cout <<"\n";   
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