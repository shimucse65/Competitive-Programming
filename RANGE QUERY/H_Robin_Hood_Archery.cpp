#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int blk=555 ;
int n, m;
int cur;
int a[N] ;
vector <int>fre(N) ;
int ans[N];

void reset (int n){
    for (int i=0;i<=n;i++){
        a[i]=ans[i]=0 ;
    }
}

struct query {
    int l, r, ind;
};

query q[N];

bool cmp (query a ,query b){
    if (a.l/blk != b.l/blk) return a.l/blk <b.l/blk ;
    return a.r <b.r ;
}

void upd(int i, int delta) {
  cur-= (fre[a[i]]&1) ;
  fre[a[i]]+=delta ;
  cur+= (fre[a[i]]&1) ;
}

void solve() {

    cin >> n >> m;
    reset (n) ;
    int mx=0ll;
    for (int i = 0; i < n; i++) {
        cin>>a[i] ;
        mx= max (mx ,a[i]) ;
    }
    fre.resize (mx+1,0ll);

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].l--; q[i].r--;
        q[i].ind = i;
    }
    
    sort (q,q+m ,cmp) ;
    
    int msl = 0, msr = -1;
    cur=0 ;
    for (int i = 0; i < m; i++) {
        int l = q[i].l, r = q[i].r, ind = q[i].ind;

        while (msr < r) upd(++msr, 1);
        while (msl > l) upd(--msl, 1);

        while (msr > r) upd(msr--, -1);
        while (msl < l) upd(msl++, -1);

        ans[ind] = cur;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i]) cout<<"NO\n" ;
        else cout <<"YES\n" ;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t--)
    solve();
}
