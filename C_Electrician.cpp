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
const int N = 1e9 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

unordered_map <int,int> mp;

int root (int n) {
    if (mp[n]==n) return n ;
    return mp[n]= root (mp[n]);
}
void solve() {

    int n;cin>>n;  
    vector < pair< pii ,pii >>v(n) ;
    vector <pii>order;

    for (int i=0;i<n ;i++) {
        cin>>v[i].ss.ff >> v[i].ss.ss >> v[i].ff.ff >>v[i].ff.ss;  
        v[i].ff.ff = v[i].ff.ff*N +v[i].ff.ss;
        order.push_back ({v[i].ff.ss ,i+1});
        mp[v[i].ss.ff]=v[i].ss.ff;
        mp[v[i].ss.ss]= v[i].ss.ss; 
    }
    sort (order.begin () , order.end ());
    sort (v.begin() ,v.end ());
    reverse (v.begin () ,v.end ());
    
    int ans=0;
    for (auto it :v) {
        int x= it.ss.ff ,y= it.ss.ss;
        x=root (x) ,y=root (y);
        if (x==y) continue;
        ans+= it.ff.ss;
        mp[x]= y;
    }
    cout <<ans <<"\n";
    for (auto it :order) cout <<it.ss <<" ";   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("input.txt","r" ,stdin);
    freopen ("output.txt" ,"w",stdout);
    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}