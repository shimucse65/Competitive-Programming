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
const int N = 5e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N];
void reset (int n){
    for (int i=0;i<=n ;i++) g[i].clear ();
}
void solve() {
   
    int n ;cin >>n ;
    reset (n);
    int a[n+1];
    for (int i=1;i<=n;i++) cin >>a[i];

    for (int i=1; i<= n-1 ;i++) {
        int u,v; cin >>u>>v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    map < int ,int>mp;
    map < int,int>tmp;
    for (int i=1 ;i<=n ;i++) tmp[i]= a[i];

    for (int i=1 ; i<=n ;i++) {
        for (auto it :g[i]) {
            if (tmp[i]== tmp[it]) mp[tmp[i]]=1;
        }
    }
    for (int i=1 ;i<=n ;i++) {
        map <int,int> cur;
        for (auto it : g[i]) {
            int x= tmp[it];
            cur[x]++;
        }
        for (auto it :cur) if (it.ss > 1) mp[it.ff]=1;
        cur.clear();
    }   
    for (int i=1 ;i<=n ;i++) cout << mp[i];
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