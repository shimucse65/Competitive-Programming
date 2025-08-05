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
    char a[3][3] ;
    for (int i=0 ;i<3 ;i++) {
        for (int j=0 ;j<3 ;j++) cin >> a[i][j];
    }

    for (int i=0 ;i<3 ;i++) {
        set < char>st;
        for (int j=0 ;j<3 ;j++) {
            st.insert (a[i][j]);
        }
        if (st.size ()==1 && *st.begin () !='.') {
            // cerr << "pp";
            cout << *st.begin () <<"\n" ;return;
        }
    }

    for (int i=0 ; i<3 ;i++) {
        set < char>st;
        for (int j=0 ;j < 3; j++) {
            st.insert (a[j][i]);
        }
        if (st.size ()==1 && *st.begin () !='.') {
           // cerr << "pp";
            cout << *st.begin () <<"\n" ;return;
        }
    }
    set < char >st;
    for (int i=0 ; i<3 ;i++ ) {
        for (int j=0 ;j<3 ;j++) {
            if (i!=j) continue;
            st.insert (a[i][j]);
        }
    
    }
    if (st.size ()==1 && *st.begin () !='.') {
        cout << *st.begin () <<"\n" ;return;
    }
    st.clear ();
    for (int i=0 ; i<3 ;i++ ) {
        for (int j=0 ;j<3 ;j++) {
           // cerr << i <<" " << j <<"\n";
            if (i+j != 2) continue;
            st.insert (a[i][j]);
        }      
    }
    if (st.size ()==1 && *st.begin () !='.') {
        cout << *st.begin () <<"\n" ;return;
    }
    cout <<"DRAW\n";   
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