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
    int a[n];
    map < int ,int>mp;
    set < int>st;
    for (int i=0;i<n ;i++) {
        cin >> a[i];
        mp[a[i]]++ ;
        st.insert (a[i]);
    }
    if (n==1) {
        cout << 1 <<" " <<1 <<"\n";return ;
    }
    if (st.size ()==1  && n > 1) {
        cout << 0 <<"\n" ; return;
    }
    int f=0 ;
    for (auto it :mp) {
        //cerr << it.ff <<" " << it.ss <<"\n";
        if (it.ss > 1) {
            f++; 
        }
    }
    if (f== mp.size ()) {
        cout << 0 <<"\n" ; return;
    }
    int l=0 , r=0;

    vector < pii > v;
    for (int i=0;i<n ;i++) {
        if (mp[a[i]] > 1) {
            v.push_back ({l ,r});
            l=i , r=i;l++ ; r++;
        } else {
            r++;
        }
    }
    v.push_back ({l,r});

    int mx= -inf ;
    pair < int ,int> ans;
    for (auto it :v) {
        int x= it.ss- it.ff + 1;
        if ( x >mx) {
            mx= x ;
          ans= {it.ff , it.ss-1};
        }
    }
    cout << ans.ff+1 <<" " << ans.ss+1 <<"\n";   
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