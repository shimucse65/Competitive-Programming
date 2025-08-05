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

int spf[N];
void siv () {
    for (int i=1 ; i<=N;i++) spf[i]=i;
    for(int i=2 ; i<N ;i+=2) spf[i]=2;
    for (int i=3 ; i*i <N ;i++) {
        if (spf[i] != i) continue;
        for (int j= i*i ; j<N ;j+=i) {
            if (spf[j]==j) spf[j]=i;
        }
    }
}
void solve() {
    int n ;cin >>n ;
    int a[n];
    for (int i=0;i<n ;i++) cin >>a[i];
   
    map < int, int> mpPrime , semi , cnt,mp ;
    int totPrime=0 , one=0 , uni=0;;
    for (int i=0;i<n ;i++) {
        mp[a[i]]++;
        if (spf[a[i]] == a[i]) {
            totPrime++;
            mpPrime[a[i]]++;
        } 
        else if (a[i]==1) one++;
        else {
            int p= spf[a[i]];
            int q= a[i]/p;
            if (spf[q] == q) {
                // cnt[p]++;
                // if (p!=q) cnt[q]++;
                semi[p*q]++;
            }
        }
    }
    int ans=0;
    
    for (auto it :mpPrime) {
        ans += it.ss * (totPrime - it.ss);
    }
    ans/=2;
    //cerr << ans <<"\n";

    for (auto it :semi) {
        //cerr << it.ff <<" " << it.ss <<"\n";
        ans+= it.ss*one;
        ans +=( it.ss * (it.ss+1)) /2;
        int p= spf[it.ff];
        int q= it.ff/p;
        ans += it.ss*mp[p] ;
        if (p!=q) ans+= it.ss*mp[q];
    }

    cout << ans <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    siv ();

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}