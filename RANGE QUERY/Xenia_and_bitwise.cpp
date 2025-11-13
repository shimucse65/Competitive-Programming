#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = (1 << 17);  
int st[N * 4], a[N];

void build(int si, int ss, int se, bool orr) {
    if (ss == se) {
        st[si] = a[ss];
        return;
    }
    int mid = (ss + se) >> 1;
    build(2 * si, ss, mid, !orr);
    build(2 * si + 1, mid + 1, se, !orr);
    if (orr) st[si] = st[2 * si] | st[2 * si + 1];
    else st[si] = st[2 * si] ^ st[2 * si + 1];
        
}

void update(int si, int ss, int se, int qi, int dx, bool orr) {
    if (ss == se) {
        st[si] = dx;
        return;
    }
    int mid = (ss + se) >> 1;
    if (qi <= mid) update(2 * si, ss, mid, qi, dx, !orr);
    else update(2 * si + 1, mid + 1, se, qi, dx, !orr);
     
    if (orr)  st[si] = st[2 * si] | st[2 * si + 1];
    else  st[si] = st[2 * si] ^ st[2 * si + 1];
       
}

void solve() { 
    int n, m;
    cin >> n >> m;
    int sz = (1 << n);  
    for (int i = 1; i <= sz; i++) cin >> a[i];
    build(1, 1, sz, n % 2 == 1);
    while (m--) {
        int ind, val;
        cin >> ind >> val;
        update(1, 1, sz, ind, val, n % 2 == 1);
        cout << st[1] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   solve () ;
}
