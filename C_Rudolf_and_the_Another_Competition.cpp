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

bool cmp ( pair < pii,int> &a , pair < pii,int> &b) {
    if (a.ff.ff != b.ff.ff) return a.ff.ff > b.ff.ff;
    if (a.ff.ss != b.ff.ss ) return a.ff.ss < b.ff.ss;
    return a.ss < b.ss;
}
   
void solve() {

    int n,m,k ; cin >>n>>m >>k;
    int a[n][m] ;
    for (int i=0 ;i<n ;i++) {
        for (int j=0 ;j<m ;j++) cin >>a[i][j];
    }
    vector < pair < pii,int> > v ;

    for (int i=0 ;i<n ;i++) {
        int cnt=0 , sm=0 ,pp=0;
        vector < int>tmp;
        for (int j=0 ;j<m ;j++) {
            tmp.push_back (a[i][j]);
        }
        sort (tmp.begin () , tmp.end ());
        for (int j=0 ;j< tmp.size () ;j++) {
            if (sm + tmp[j] <= k) {
                sm += tmp[j] ; cnt++;
                pp += sm;
            }
        }
        v.push_back ({ {cnt ,pp },i+1});
    }

    sort (v.begin () ,v.end () ,cmp);
    
    // for (auto it :v) {
    //     cerr << it.ff.ff <<" " << it.ff.ss <<" " << it.ss <<"\n";
    // }
    for (int i=0 ;i<v.size () ;i++) {
        if (v[i].ss==1) {
            cout << i + 1 <<"\n"; return;
        }
    }
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