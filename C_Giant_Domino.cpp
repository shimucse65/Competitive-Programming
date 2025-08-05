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
    int n; cin >>n ;
    vector <int> a(n);
    for (int i=0 ;i<n ;i++) cin >>a[i];
    
    sort (a.begin(),a.end());   
    a.erase(unique (a.begin(), a.end()),a.end());
    int p = a[0] , q= a[n-1];
    vector<int> v;
    v.push_back (p);

    for (auto it :a) cerr << it <<" "; cerr <<"\n";

    int cnt =0;
    while ( v.back() != q) {
       // cnt++;
        int id1 =  lower_bound(a.begin(), a.end(), p)-a.begin();
        int id2 =  lower_bound(a.begin(), a.end(), p*2)-a.begin();
        cerr << id1 <<" " << id2 <<"\n";
        if (id1 == id2) {
            cout << -1 <<"\n"; return;
        } else {
            if (a[id2] == p*2) {
                v.push_back (a[id2]); p= a[id2];
            } else {
                if (id2 != 0) {
                    if (id1 == id2-1) {
                        cout << -1 <<"\n"; return;
                    }
                    v.push_back (a[id2-1]); p = a[id2-1];
                } else {
                    cout << -1 <<"\n"; return;
                }
            }
        }
       // if (cnt == 5) break;
    }
    cout << v.size() <<"\n";
   // for (auto it :v) cerr << it <<" "; cerr <<"\n";
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