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

vector <int>divi (int n) {
    vector <int>res ;
    for (int i=1 ;i*i <=n ;i++) {
        if (n%i==0) {
            res.push_back (i) ;
            if(i*i !=n) {
                res.push_back (n/i) ;
            }
        }
    }
    sort (res.begin () , res.end ()) ;
    return res ;
}
void solve() {
   int n; cin >> n;
   vector <int> dd = divi(n);

   map <int, int> mp;
   int tmp = n;
   while(tmp > 0) {
        int x = tmp % 10 ; tmp /= 10;
        mp[x]++;
   }
   int cnt =0;
   for(auto it : dd) {
    if (it == 1 || it == n) continue;
     int cur = it;
     map <int, int> mp2;
     int tmp2 = cur;
     while(tmp2 > 0) {
        int x = tmp2 % 10 ; tmp2 /= 10;
        mp2[x] ++;
     }
     if (mp == mp2) cnt ++;
   }
   cout << cnt << "\n";    
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