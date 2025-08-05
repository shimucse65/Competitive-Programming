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
    int n,k; cin>>n>>k ;
    vector <int>a ,b,both;
    for (int i=0;i<n ;i++) {
        int x,y,z;cin>>x>>y>>z;
        if (y==1 && z==1) both.push_back (x);
        else if (y==1) a.push_back (x);
        else if (z==1) b.push_back (x);
    }
    sort (a.begin () ,a.end ());
    sort (b.begin () , b.end ());

    int mn= min (a.size () , b.size());

    for (int i=0;i<mn ;i++) {
        both.push_back (a[i]+b[i]);
    }
    sort (both.begin () , both.end ());

    if (both.size () < k) cout <<-1 <<"\n";
    else {
        int sm=0;
        for (int i=0;i<k ;i++) sm+= both[i];
        cout << sm <<"\n";
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}