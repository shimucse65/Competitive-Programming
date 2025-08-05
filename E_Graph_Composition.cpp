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

class DisjointSet {    
public:
    vector<int> rank, parent, sz;
    
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
 
    int findPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
 
    void unionByRank(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
 
    void unionBySize(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
};
void solve() {
    int n ,a,b; cin>>n>>a>>b ;
    vector < pii > e1 (a) , e2(b);
    DisjointSet ds1(n) , ds2(n); 

    for (int i = 0 ; i < a ;i++) {
        int x,y;cin>>x>>y ;
        e1[i]= {x,y} ;
    }

    for (int i=0 ; i<b ;i++) {
        int x,y;cin >>x>>y ;
        e2[i]= {x,y};
        ds2.unionBySize (x,y) ;
    }
    int cnt=0;
    for (auto it :e1) {
        if (ds2.findPar (it.ff) != ds2.findPar (it.ss)) {
            cnt++ ;
        } else ds1.unionBySize (it.ff , it.ss);
    }
    
    for (auto it :e2) {
        if (ds1.findPar (it.ff) != ds1.findPar (it.ss)) {
            cnt++ ;
            ds1.unionBySize (it.ff , it.ss);
        } 
        //else ds1.unionBySize (it.ff , it.ss);
    }
    cout << cnt <<"\n";
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