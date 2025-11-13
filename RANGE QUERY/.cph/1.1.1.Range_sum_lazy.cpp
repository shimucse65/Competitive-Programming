#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e6 + 10;

#define lc (id << 1)
#define rc (id << 1 | 1)

struct Node {
    int sum, lz; // sum represents the range sum, lz is for lazy updates
    Node() : sum(0), lz(0) {}
    Node(int s) : sum(s), lz(0) {}
};

int n, m;
vector<Node> seg(4 * N);

// push function ensures any pending updates (lazy values) are propagated to child nodes
void push(int id, int l, int r) {
    if(seg[id].lz) {
        seg[id].sum += seg[id].lz * (r - l + 1); // Apply the lazy value to the current node
        if(l != r) { // If not a leaf node, propagate the lazy value to child nodes
            seg[lc].lz += seg[id].lz;
            seg[rc].lz += seg[id].lz;
        }
        seg[id].lz = 0; // Reset the lazy value for the current node
    }
}

// pull function recalculates the sum of the current node based on its children
void pull(int id) {
    seg[id].sum = seg[lc].sum + seg[rc].sum;
}

// build function initializes the segment tree
void build(int id = 1, int lo = 1, int hi = n) {
    if(lo == hi) {
        seg[id].sum = 0; // Initialize leaf nodes with 0
    } else {
        int mid = (lo + hi) / 2;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(id); // Recalculate current node based on children
    }
}

// update function to increment a range [l, r] by value x
void upd(int l, int r, int x, int id = 1, int lo = 1, int hi = n) {
    push(id, lo, hi); // Ensure any pending updates are applied
    if(l > hi || r < lo) return; // No overlap
    if(l <= lo && hi <= r) { // Total overlap
        seg[id].lz += x; // Add the update value to lazy
        push(id, lo, hi); // Apply the lazy value immediately
        return;
    }
    
    // Partial overlap
    int mid = (lo + hi) / 2;
    upd(l, r, x, lc, lo, mid);
    upd(l, r, x, rc, mid + 1, hi);
    pull(id); // Recalculate current node based on children
}

// query function to get the sum in the range [l, r]
int query(int l, int r, int id = 1, int lo = 1, int hi = n) {
    push(id, lo, hi); // Ensure any pending updates are applied
    if(l > hi || r < lo) return 0; // No overlap
    if(l <= lo && hi <= r) { // Total overlap
        return seg[id].sum;
    }

    // Partial overlap
    int mid = (lo + hi) / 2;
    return query(l, r, lc, lo, mid) + query(l, r, rc, mid + 1, hi);
}

void solve() {
    cin >> n >> m;
    
    for(int i = 0; i <= 4 * n; i++) seg[i] = Node();

    build(); // Build the segment tree

    for(int i = 0; i < m; i++) {
        int type; cin >> type;
        if(type == 1) {
            int l, r, x;
            cin >> l >> r >> x; // Update range [l, r] by x
            upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r; // Query sum in range [l, r]
            cout << query(l, r) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while(t--) {
        solve();
    }
}

