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

int check (int n) {
    int cnt=0 ;
    while (n > 0) {
        int x= n % 10 ;
        if (x !=0) cnt ++ ;
        n/= 10;
    }
    return cnt==1 ;
}
void solve() {
    int n ;cin >> n;

    if (n < 10) {
        cout << n <<"\n"; return;
    }
    int cnt=0 ;
    string s= to_string (n) ;   
    int sz= s.size ();
    sz--;
    cnt += (sz*9) ;
    
    s[0]= '1';
    for (int i=1 ;i< s.size () ;i++) s[i]='0';
    int nn = stoi (s) ;

    // for (int i= nn ;i<=n ;i+=10) {
    //     if (check (i)) cnt++;
    // }
    cnt += (n/nn);

    cout <<cnt << "\n";
    
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