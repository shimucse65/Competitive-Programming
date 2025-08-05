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
    int n;cin >>n ;
    int a[n];
    map <int,int>mp;
    for(int i=0 ;i<n ;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    set <int>st;
    vector <int> ans;
    for (int i=0; i<n ;i++) st.insert (a[i]);

    int cur =0 ;
    for (int i = 0 ;i < N ;i++) {
        if (!st.count (i)) {
            cur =i ; break;
        }
    }

    for (auto it :mp) {
        if (it.ss > cur) ans.push_back (0);
    }
    
    map <int ,int> mp2 ;
    for (auto it:mp) {
        if (it.ff > cur) continue;
        mp2[it.ff] = it.ss;
    }

    map <int ,int> mp3 ;
    for (auto it :mp2) {
        mp3[it.ss]= it.ff;
    }
   
    set < int >st2;
    for (auto it :mp3) st2.insert (it.ff);

    
    int cc=inf , koyta=0;
    while (st2.size () > 0) {

        int xx= *st2.begin ();
        int tmp= xx;
        st2.erase (xx);

        if (mp3[xx] < cc) {
            int y= mp3[xx];
            xx -= koyta;
            for (int i=0 ;i<xx ;i++) ans.push_back (y+1);
            koyta += tmp;
            cc= y;
        } else {
            for (int i=0 ; i< xx ;i++) ans.push_back (0);
            cc = mp[xx];
        }     
    }

    sort (ans.begin () , ans.end () , greater <int> ());
    cout<< ans.size () <<"\n";
    for (auto it :ans) cout << it <<" " ; cout <<"\n";
   
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