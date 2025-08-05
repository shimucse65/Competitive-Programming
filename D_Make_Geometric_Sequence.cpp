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

bool check (vector <int> &v){
    for(int i = 1; i + 1 < v.size(); i++){
        if(v[i] * v[i] != v[i - 1] * v[i + 1])return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int>pos, neg;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > 0)pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    int pp = pos.size(), nn = neg.size();
    sort(pos.begin(), pos.end());
    sort(neg.rbegin(), neg.rend());

    if(pp == 0 || nn == 0) {
        sort(a.begin(), a.end());
        bool f = check (a);
        if(f) cout <<"Yes\n";
        else cout << "No\n";
        return;
    }
    if (abs(pp - nn) > 1) {
        cout << "No\n"; return;
    }
    if (pp == nn) {
        vector<int> v;
        int ii = 0;
        for(int i = 0; i < pos.size(); i++) {
            v.push_back(pos[ii]);
            v.push_back(neg[ii++]);
        }
        if (check(v)) {cout << "Yes\n"; return; }

        v.clear();
        ii = 0;
        for(int i = 0; i < pos.size(); i++) {
            v.push_back(neg[ii]);
            v.push_back(pos[ii++]);
        }
        if (check(v)) cout << "Yes\n";
        else cout << "No\n"; return;
    }
    if (pp > nn) {
        vector<int> v;
        int ii = 0;
        for(int i = 0; i < nn; i++) {
            v.push_back(pos[ii]);
            v.push_back(neg[ii++]);
        }
        v.push_back(pos[ii]);
        if (check(v)) cout << "Yes\n";
        else cout << "No\n"; return;
    }
    vector<int> v;
    int ii = 0;
    for(int i = 0; i < pp; i++) {
        v.push_back(neg[ii]);
        v.push_back(pos[ii++]);
    }
    v.push_back(neg[ii]);
    if (check(v)) cout << "Yes\n";
    else cout << "No\n";   
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