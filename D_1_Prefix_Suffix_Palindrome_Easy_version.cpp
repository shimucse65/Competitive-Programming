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

bool isPalindrome (string s) {
    string  t=s ;
    reverse (s.begin () ,s.end ()) ;
    if (t==s) return true ;
    return false ;
}

void solve() {
    string s;cin>>s ;
    int n= s.size () ;
    if (n==1) {
        cout <<s <<"\n"; return ;
    }
    if (n==2) {
        if (s[0]==s[1]) cout <<s <<"\n" ;
        else cout <<s[0] <<"\n" ; return ;
    }
    if (isPalindrome (s)) {
        cout <<s <<"\n" ; return ;
    }
    string first , middle ,last ;
    int i=0 ,j=n-1 ;
    int shuru=0 ,sesh=n-1 ;
    while (i<=j) {
        if (s[i]==s[j]) {
            first.push_back (s[i]) ;
            last.push_back (s[j]) ;
            i++ ;j--;
        }
        else {
            shuru=i ;sesh= j ; break ;
        }
    }
  //  cerr << first <<"\n" ;
    int op1 ,op2 ;
    string tmp1 ,tmp2 ;
    for (int i=shuru ;i<=sesh ;i++) {
        string tmp="" ;
        for (int j=shuru ;j<=i;j++) tmp+= s[j] ;
        if (isPalindrome (tmp)) {
            op1= tmp.size () ;
            tmp1= tmp ;
        }
    }
    //cerr <<op1 <<" "<<tmp1 <<"\n" ;
     for (int i=sesh ;i>=shuru ;i--) {
        string tmp="" ;
        for (int j=sesh ;j>=i ;j--) tmp+= s[j] ;
        if (isPalindrome (tmp)) {
            op2= tmp.size () ;
            tmp2= tmp ;

        }

     }
     if (op1 >op2) middle= tmp1 ;
     else middle = tmp2 ;

     reverse (last.begin () ,last.end ()) ;

     cout <<first <<middle <<last <<"\n" ;

    
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