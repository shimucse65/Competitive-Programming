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

    int n, k; cin >> n >> k;
    vector<pii> v(n);
    sort (v.begin(), v.end());
    map<int, int>mp;
    for (auto &[a,b] : v) {
        cin >> a >> b;
        mp[a]++;
        mp[b + 1]--;
    }
   // for (auto &[a, b] : mp) cerr << a << " " << b << endl;

    int sm = 0;
    for (auto &[a,b] : mp) {
        sm += b;
        b = sm;
    }
    vector <pii> tmp;
    for (auto &[a, b] : mp) tmp.push_back ({a, b});
  //  for (auto &[a, b] : mp) cerr << a << " " << b << endl;
   vector <pii>ans;
    int l = -1, r=0;
    for (int i = 0; i + 1 < tmp.size(); i++) {
        int currVal = tmp[i].ss;
        int currPos = tmp[i].ff;
        int nextPos = tmp[i + 1].ff;

        if (currVal >= k) {
            if (l == -1) l = currPos;
            r = nextPos - 1;
        } else {
            if (l != -1) {
                ans.push_back({l, r});
                l = r = -1;
            }
        }
    }

    if (l != -1) {
        ans.push_back({l, tmp.back().ff - 1});
    }

    cout << ans.size() <<"\n";
    for(auto it : ans) cout << it.ff <<" " << it.ss <<"\n";    
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