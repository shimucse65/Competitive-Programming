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

class ST {

public:
    struct Node {
        int mx, mn;
        Node() : mx(-inf), mn(inf) {}
        Node(int a, int b) : mx(a), mn(b) {}
    };

    vector<Node> seg;
    
    ST(int n) {
        seg.resize(4 * n + 1);
    }

    void pull(int ind) {
        seg[ind].mx = max(seg[2 * ind + 1].mx, seg[2 * ind + 2].mx);
        seg[ind].mn = min(seg[2 * ind + 1].mn, seg[2 * ind + 2].mn);
    }

    Node merge(Node a, Node b) {
        Node ret;
        ret.mx = max(a.mx, b.mx);
        ret.mn = min(a.mn, b.mn);
        return ret;
    }

    Node query(int ind, int low, int high, int l, int r) {

        if(l > high || r < low) return Node();
        if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        auto left = query(2 * ind + 1, low, mid, l, r);
        auto right = query(2 * ind + 2, mid + 1, high, l, r);
        return merge(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = Node(val, val);
            return;
        }

        int mid = low + (high - low) / 2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        
        pull(ind);
    }
};

void solve() {
    int n, q; cin>>n>>q;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    ST seg1(n), seg2(n);
    for(int i = 0; i < n; i++) seg1.update(0, 0, n - 1, i, a[i] - i);
    for(int i = 0; i < n; i++) seg2.update(0, 0, n - 1, i, a[i] + i);

    auto q1 = seg1.query(0, 0, n - 1, 0, n - 1);
    auto q2 = seg2.query(0, 0, n - 1, 0, n - 1);

    int mx = q1.mx - q1.mn;
     mx = max(mx, q2.mx - q2.mn);

    cout<<mx<<endl;

    while(q--) {
        int i, x; cin>>i>>x;
        --i;
        seg1.update(0, 0, n - 1, i, x - i);
        seg2.update(0, 0, n - 1, i, x + i);

        q1 = seg1.query(0, 0, n - 1, 0, n - 1);
        q2 = seg2.query(0, 0, n - 1, 0, n - 1);
        mx = q1.mx - q1.mn;
        // mx = max(mx, q2.mx - q2.mn);

        cout<<mx<<endl;
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