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
    int n ; cin >> n ;
    int a[n];
    set <int> st;
    for (int i= 0 ; i<n ;i++) {
        cin >> a[i];
        st.insert (a[i]);
    }
    if( st.size () == 1) {
        cout << 0 <<"\n"; return;
    }
    int id1=0 , id2= n-1;
    for (int i =0 ; i< n ;i++) {
        if (a[i] != a[0]) {
            id1 = i - 1 ; break;
        }
    }
    for (int i= n-1 ; i >= 0 ; i--) {
        if ( a[i] != a[n-1]) {
            id2 = i + 1; break;
        }
    }
    int cnt =0;
    int cur = 0;
    //cerr << id1 <<" " << id2 <<"\n";

    for (int i=id1 ; i<= id2 ;i++) {
        if (a[i] == 1) {
            while (a[i]==1 && i < n) {
                cur ++ ; i++;
            }
            i--;
        } else {
            if (cur & 1) {
                int tmp = 0;
                while (a[i]==2 && i < n) {
                    cerr << i <<" " << a[i] <<"\n";
                    tmp ++ ; i++;
                }
                i-- ;
                //cerr << tmp <<"\n";
                cnt += tmp ; tmp=0;
            } else {
                cnt += cur/2; cur =0;
            }
        }
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