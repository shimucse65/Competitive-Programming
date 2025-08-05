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

    int n;cin>>n ;
    string s ;cin>>s ;
    vector <int> r,g,b;
    for (int i=0 ;i<n;i++) {
        if (s[i]=='R') r.push_back (i) ;
        else if (s[i]=='G') g.push_back (i) ;
        else b.push_back (i) ;
    }
    int cnt=0 ;
    for (int i=0 ;i<n-2;i++) {
        for (int j=i+1 ; j<n-1;j++) {

            if (s[i]==s[j]) continue ;
          
             char ch='a' ;
            set < char >st ;
            st.insert (s[i]) ;
            st.insert (s[j]);
            if (!st.count ('R')) ch= 'R' ;
            else if (!st.count ('G')) ch= 'G' ;
            else ch='B' ;
         
            if (ch=='R') {
                int it= upper_bound (r.begin () , r.end (),j)- r.begin () ;
                cnt+=(r.size ()- it) ;
                if (it-j== j-i)  cnt-- ;

            } else if (ch=='G') {
                int it= upper_bound (g.begin () , g.end (),j)- g.begin () ;
                cnt+= (g.size ()- it) ;
                if (it-j== j-i)  cnt-- ;
            } else {
                int it= upper_bound (b.begin () , b.end (),j)- b.begin () ;
                cnt+= (b.size ()- it) ;
                if (it-j== j-i)  cnt-- ;
            }
            st.clear () ;
            
        }
      
    }  
    cout <<cnt <<"\n" ;
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