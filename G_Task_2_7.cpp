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
int lcm (int a, int b) {
    return (a*b)/(__gcd (a,b));
}
vector <int> primeFact (int n) {
    vector <int> res;
    for (int i=2 ;i*i <= n ;i++) {
        if (n%i==0) {
            while (n % i==0) {
                res.push_back (i) ; n /= i;
            }
        }
    }
    if (n > 1) res.push_back (n);

    return res;
}
void solve() {

    int a,b,lc; cin >> a>> b >> lc ;


    if (lc % a !=0 || lc % b!= 0) {
        cout <<"impossible" <<"\n"; return;
    }
   
    vector <int >  ll = primeFact (lc) ;
    vector < int > aa=  primeFact (lcm (a,b)) ;
    
     map < int , int > need ;
     for (int i=0 ;i<ll.size () ;i++) need [ll[i]] ++;

     map < int,int> ache;
     for (int i=0 ;i<aa.size () ;i++) ache[aa[i]]++;

     
     int ans=1 ;
     for (auto it : need) {
        if (it.ss <=  ache[it.ff]) continue;

        ans *= pow (it.ff , it.ss);
     }

     cout << ans <<"\n";   
}  

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
         cout<<"Case "<<c++<<": ";
        solve();
    }
}