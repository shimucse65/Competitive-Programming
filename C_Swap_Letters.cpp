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
    string s,t ;cin>>s>>t ;
    vector <int> ab , ba;
    for (int i=0 ;i<n ;i++) {
        if (s[i]=='a' && t[i]=='b') ab.push_back (i);
        else if (s[i]=='b' && t[i]=='a') ba.push_back (i);
    }
    int sz= ab.size ()+ ba.size();
    if (sz&1) {
        cout << -1 <<"\n"; return;
    }
    if (ab.size () & 1) {

        // for (auto it :ab) cerr <<  it <<" " ; cerr <<"\n";
        // for (auto it :ba) cerr << it <<" " ;  cerr <<"\n";
      
        cout <<( sz/2)+1 <<"\n";
        int x= ab.size ()-1;
        sz= x/2 ;
        int ind=0;    
        for (int i=0 ;i< sz ;i++) {
            cout << ab[ind] + 1 <<" " << ab[ind+1] + 1 <<"\n";
            ind+=2;
        }
        x= ba.size ()-1 ;
        sz= x/2;
        ind=0;
        for (int i=0 ; i <sz ;i++) {
            cout << ba[ind] +1  <<" " << ba[ind+1]+1 <<"\n";
            ind += 2;
        } 
        cout << ba.back () + 1  <<" " << ba.back()+1 <<"\n";
        cout << ab.back () + 1 <<" " <<ba.back () + 1 <<"\n";    
    }  
    else {
        cout << sz/2 <<"\n";
        int ind=0;
        sz= ab.size ()/2;

        for (int i=0 ;i< sz ;i++) {
            cout << ab[ind]+1 <<" " << ab[ind+1]+1 <<"\n";
            ind+=2;
        }
        ind=0;
        sz= ba.size()/2;
        for (int i=0 ; i <sz;i++) {
            cout << ba[ind]+1 <<" " << ba[ind+1] + 1<<"\n";
            ind += 2;
        }

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