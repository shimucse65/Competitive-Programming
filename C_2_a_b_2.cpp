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
const int N = 1e18;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int  pw(int a, int b)
{
    if(b == 0) return 1;
    int x = pw(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}
void solve() {
    int n; cin >>n ;
    vector <long long > v;
    set <long long >st;
    
    for (int i=1 ; i<=60;i++) {
        for (int j=1 ; j <=1000;j++) {
            int xx = pw (2,i);
            int yy = pw (j,2);
            if (xx *1ll *yy > N) break;
            st.insert (pw (2,i) *1ll* pw (j,2));
        }
    }
    for (auto it :st)v.push_back (it);
   // for (auto it :v) cerr << it <<" " ; cerr <<"\n";
    int it= lower_bound (v.begin () , v.end () , n)- v.begin ();
    cout << it + 1 <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
   // while(t--)
     {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}