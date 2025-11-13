#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int ans[N];
int cnt[N];
int a[N];

int tmp = 0;

struct query {
    int l, r, ind;
};
query q[N];
int sz;

bool cmp(query x, query y) {
    if (x.l / sz == y.l / sz) return x.r < y.r;
    return x.l / sz < y.l / sz;
}

void add(int ind) {
    if (a[ind] >= N) return;
    if (cnt[a[ind]] == a[ind]) tmp--;
    cnt[a[ind]]++;
    if (cnt[a[ind]] == a[ind]) tmp++;
}

void remve(int ind) {
    if (a[ind] >= N) return;
    if (cnt[a[ind]] == a[ind]) tmp--;
    cnt[a[ind]]--;
    if (cnt[a[ind]] == a[ind]) tmp++;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; 
        q[i].r--; 
        q[i].ind = i;
    }
    
    sz = sqrt(n);
    sort(q, q + m, cmp);
    
    int msl = 0, msr = 0; 
    add(0); 
    
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r;
        
        while (msr < r) {
            msr++;
            add(msr);
        }
        
        while (msr > r) {
            remve(msr);
            msr--;
        }
        
        while (msl < l) {
            remve(msl);
            msl++;
        }
        
        while (msl > l) {
            msl--;
            add(msl);
        }
        
        ans[q[i].ind] = tmp;
    }
    
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
