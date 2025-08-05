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
    int n ; cin >> n;
    map <int ,int>mp;
    for (int i=2 ;i<=n ;i++) {

        int tmp=i ;
        for (int j=2; j*j <= tmp ;j++) {
            if (tmp % j==0) {
                while (tmp % j==0) {
                    mp[j]++;
                    tmp/=j;
                }
            }
        }
        if (tmp > 1) mp[tmp]++;
    }
    cout << n <<" " <<"=" <<" " ;
    int cnt=0;
    for (auto it :mp) {
        cout << it.ff <<" " << "(" <<it.ss <<")"<<" ";
        cnt ++ ;
        if (cnt != mp.size ()) cout <<"*"<<" ";
    }
    cout <<"\n";    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<":"<<" ";
        solve();
    }
}