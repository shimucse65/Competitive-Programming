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
    string t=s ;
    reverse (s.begin () ,s.end ()) ;
    if (s==t) return true ;
    return false ;

}
void solve() {

    int n ;cin>>n ;
    string s ;cin>>s ;
    if (check (s)) {
        cout <<"Palindrome already"<<"\n" ; return ;
    }
    map <char ,int>mp ;
    for (int i=0;i<s.size () ;i++) {
        mp[s[i]]++ ;
    }
    int cnt=0;
    char c;
    for (auto it :mp) {
        if (it.ss==1) {
            c= it.ff ; cnt++ ;
        }
    }
    if (cnt>1) {
        cout <<"Not possible"<<"\n" ; return ;
    }

    cout <<"Yes\n" ;
    vector <char >v ;
    sort (s.begin () ,s.end()) ;
    for (int i=0;i<s.size();i++) v.push_back (s[i]) ;
   // for (auto it :v) cerr <<it;
    if (cnt==0) {
    vector <char>tmp ;    
    for (int i=0;i<v.size () ;i+=2) tmp.push_back (v[i]) ;
    for (auto it :tmp) cout <<it ;
    reverse (tmp.begin () ,tmp.end ());
    for (auto it :tmp) cout <<it ;
    cout <<"\n" ;
    return ; 
  }

    vector <char>tmp ;  
    int cur=0 ;  
    int ds=( v.size()-1)/2 ;
    for (int i=0;i<v.size () ;i+=2) {
        if (v[i]==c) continue ;
        if (cur==ds ) break;
        tmp.push_back (v[i]) ;cur++;
    }
    for (auto it :tmp) cout <<it ;
    cout <<c;
    reverse (tmp.begin () ,tmp.end ());
    for (auto it :tmp) cout <<it ;
    cout <<"\n" ;   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
        cout <<"\n" ;
    }
}