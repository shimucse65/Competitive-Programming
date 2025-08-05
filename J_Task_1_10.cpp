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
    set < pii >st ;
    st.insert ({1,2});
    st.insert ({1,3});
    st.insert ({2,4});
    st.insert ({2,5});
    st.insert ({3,6});
    st.insert ({3,7});
    st.insert ({4,8});
    st.insert ({4,9});
    st.insert ({5,10});
    st.insert ({5,11});
    st.insert ({6,12});
    st.insert ({6,13});
    st.insert ({7,14});
    st.insert ({7,15});

    int a,b ; cin >>a >>b ;
    if (a > b) swap (a,b) ;
    if (st.count ({a,b})) cout <<"Yes\n";
    else cout <<"No\n";


    
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