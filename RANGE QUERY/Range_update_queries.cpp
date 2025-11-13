#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200005;
long long seg[4 * MAXN], lazy[4 * MAXN]; 
int n, q;


void build(vector<int>& arr, int ind, int low, int high) {
    if (low == high) {
        seg[ind] = arr[low]; 
    } else {
        int mid = (low + high) / 2;
        build(arr, 2 * ind, low, mid);
        build(arr, 2 * ind + 1, mid + 1, high);
        seg[ind] = seg[2 * ind] + seg[2 * ind + 1]; 
    }
}


void propagate(int ind, int low, int high) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind]; 
        if (low != high) {
            lazy[2 * ind] += lazy[ind];       
            lazy[2 * ind + 1] += lazy[ind];   
        }
        lazy[ind] = 0; 
    }
}


void update(int ind, int low, int high, int l, int r, int val) {
    propagate(ind, low, high);
    if (high < l || low > r) return; 
    if (low >= l && high <= r) { 
        lazy[ind] += val; 
        propagate(ind, low, high); 
        return;
    }
   
    int mid = (low + high) / 2;
    update(2 * ind, low, mid, l, r, val);
    update(2 * ind + 1, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1]; 
}

long long query(int ind, int low, int high, int pos) {
    propagate(ind, low, high); 
    if (low == high) return seg[ind]; 
    int mid = (low + high) / 2;
    if (pos <= mid) return query(2 * ind, low, mid, pos);
    else return query(2 * ind + 1, mid + 1, high, pos);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    build(arr, 1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u); 
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << query(1, 1, n, k) << '\n'; 
        }
    }

    return 0;
}
