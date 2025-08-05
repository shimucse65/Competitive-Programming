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
    int a[n+1];
    for(int i=1 ;i<=n ;i++) cin>>a[i];


    int pos=0 , neg=0;
    vector <pii>ans;

    for (int i=1 ;i<=n ;i++) {
        if (a[i] == 1) {
            int cnt=0 ;
            int l=i;
            while (a[i] == 1 && i <= n) {
                cnt++ ;i++;
            }
            i--;
            if (neg > 0) {
                neg-- ,cnt--;
                ans.push_back ({l,l}); l++;
            }
            int r=i;
            if (cnt == 0) continue;
            else if (cnt % 2 == 0) {
                ans.push_back ({l,r});
            } else if (cnt & 1) {
                pos ++; 
                if (cnt == 1) ans.push_back ({l,l});
                else {
                    ans.push_back ({l,r-1});
                    ans.push_back ({r,r});
                }
            }
        }


        else {
            int cnt=0 ;
            int l=i;
            while (a[i] == -1 && i <= n) {
                cnt ++; i++;
            }
            i--;
            if (pos > 0) {
                pos -- ,cnt--;
                ans.push_back ({l,l}); l++;
            }
            int r=i;
            if (cnt == 0) continue;
            else if (cnt % 2 == 0) {
                ans.push_back ({l,r});
            } else if (cnt & 1) {
                neg ++; 
                if (cnt == 1) ans.push_back ({l,l});
                else {
                    ans.push_back ({l,r-1});
                    ans.push_back ({r,r});
                }
            }
        }
    }
    if (pos != 0 || neg != 0) cout << -1 <<"\n";
    else {
        cout << ans.size() <<"\n";
        for (auto it :ans) cout << it.ff <<" " <<it.ss <<"\n";
        return;
    }
    
    
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