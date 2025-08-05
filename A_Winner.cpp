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

    int n ;cin>>n ;
    map <string ,int>mp ;
    vector <pair <string ,int> > v;
    for (int i=0 ;i<n;i++) {
        string s; cin>>s ;
        int sc ;cin>>sc ;
        mp[s]+= sc ;
        v.push_back ({s,sc});
    }
    string ans;
    int cur= -inf ;
    for (auto it :mp) {
        cur= max (cur , it.ss) ;   
    }
    set <string >st ;
    for (auto it :mp) {
        if (it.ss==cur) st.insert (it.ff) ;
    }
    map <string ,int>mp2 ;
    for(auto it :v) {
        mp2[it.ff]+= it.ss ;
        if (mp2[it.ff] >= cur) {
            if (st.count (it.ff)) {
                cout << it.ff ; return ;
            }
        }
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