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

bool check (string s) {
    string nn = s;
    reverse(s.begin(), s.end());
    return nn == s;
}
string Base (int n , int a) {
    string ans = "";
    while(n > 0) {
        int x = n % a;
        n /= a;
        char c =char(x +'0');
        ans.push_back(c);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


void solve() {
    int a, n; cin >> a >> n;
    int sm = 0;
    //1-9
    
        for(int i = 1 ; i <= 9 ;i++) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
            if(i > n) break;
        }

    
        //11 - 99
        for(int i = 11 ; i <= 99 ;i+=11) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
            if (i > n) break;
        }

       // 101 - 999

         for(int i = 101 ; i <= 999 ;i+=10) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
        }

        //1001 - 9999

         for(int i = 1001 ; i <= n ;i += 10) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
            if (i > n) break;
        }

        
       // 10001 - 99999
         for(int i = 10001 ; i <= 99999 ;i+=10) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
        }

        //100001 - 999999

         for(int i = 1 ; i <= n ;i++) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
        }
        //1000001 - 9999999

         for(int i = 1 ; i <= n ;i++) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
        }

         for(int i = 1 ; i <= n ;i++) {
            string ss= to_string(i);
            if (!check (ss)) continue;
            string pp = Base(i, a);
            if (!check (pp)) continue;
            sm += i;
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