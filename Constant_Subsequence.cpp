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

bool check (int x ,vector <int> pos , vector <int> neg) {
    int i=0 ,j=0 ,sm=0;
    while ( i < pos.size ()  && j < neg.size ()  ) {
        if (sm + pos[i] <= x) {
            sm+= pos[i++];
        } else sm+= neg[j++];
        if (sm < 0) sm = 0;
    }
    while (i < pos.size () ) sm += pos[i++];
    return sm <= x;
}

void solve() {
    int n ;cin>>n ;
    int a[n];
    for (int i=0 ;i<n ;i++) cin>>a[i];
    vector <int>pos ,neg ;
    for (int i=0 ;i<n ;i++) {
        if (a[i] >=0) pos.push_back (a[i]);
        else neg.push_back (a[i]);
    }
    int l=0 ,r=inf ,ans=0;
    while (l<=r) {
        int mid= (l+r)/2 ;
        if (check (mid ,pos ,neg)) {
            ans= mid ; r= mid-1;
        } else l= mid+1 ;
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