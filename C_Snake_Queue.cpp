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
const int N = 3e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int pf[N];

void solve() {
    int n ;
    cin >> n;
    vector <int> v ;
    int cur=0;
    int ind=0 ;
    pf[0]=0;
   
    int tc= 1;
    map < int , int> mp ;
    mp[tc++]=0;
    int f=0;
    for (int i=1 ; i<= n ;i++) {
        int ty; cin>>ty ;
        if (ty==1) {
            int x ;cin >>x ;
            pf[i]= pf[i-1]+ x;
            v.push_back (x);
            mp[tc++]= pf[i];
        } 
        else if (ty==2) {
            int x= v[ind++] ;
            cur += x;
           // cerr << x <<" " << cur <<"\n"; 
            pf[i]= pf[i-1];   
        } else {
            int  x; cin>>x ;  
            for (auto it :mp) cerr << it.ff <<" " << it.ss <<"\n";
            cerr <<"\n";
            if (f==0) {
                 cout << mp[x]-cur <<"\n"; f=1 ;
            }
            else 
            {
                x++ ;
                cout << mp[x]-cur <<"\n";
            }     
            pf[i]= pf[i-1];
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