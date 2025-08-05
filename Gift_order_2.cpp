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
int a[N];
#define lc 2*ind+1 
#define rc 2*ind+2

struct node {int mx1 ,mn1 ,mx2 ,mn2 ,ans;};
node seg[4*N];

void build (int ind ,int lo, int hi) {
    if (lo==hi) {
        seg[ind].mx1= a[lo]+ (lo+1);
        seg[ind].mn1= a[lo]+ (lo+1);
        seg[ind].mx2= a[lo]- (lo+1);
        seg[ind].mn2= a[lo]- (lo+1);
        seg[ind].ans=0;
        return ;       
    }
    int mid= (lo+hi)/2 ;
    build (lc ,lo,mid);
    build (rc , mid+1 ,hi);

    seg[ind].mx1= max (seg[lc].mx1 , seg[rc].mx1);
    seg[ind].mn1= min (seg[lc].mn1 , seg[rc].mn1);
    seg[ind].mx2= max (seg[lc].mx2 , seg[rc].mx2);
    seg[ind].mn2= min (seg[lc].mn2 , seg[rc].mn2);
    seg[ind].ans= max (seg[lc].ans , seg[rc].ans);
    seg[ind].ans= max (seg[ind].ans, seg[lc].mx1- seg[rc].mn1);
    seg[ind].ans= max (seg[ind].ans, seg[rc].mx2- seg[lc].mn2);

}

int query () {
    return seg[0].ans;
}
void update (int ind ,int lo ,int hi ,int id , int val) {
    if (lo==hi) {
        seg[ind].mx1= val + (lo+1);
        seg[ind].mn1= val + (lo+1);
        seg[ind].mx2= val - (lo+1);
        seg[ind].mn2= val - (lo+1);
        seg[ind].ans=0;
        return ; 
    }

    int mid= (lo+hi)/2 ;
    if (id <=mid )update(lc ,lo,mid ,id ,val);
    else update (rc , mid+1 ,hi ,id ,val);

    seg[ind].mx1= max (seg[lc].mx1 , seg[rc].mx1);
    seg[ind].mn1= min (seg[lc].mn1 , seg[rc].mn1);
    seg[ind].mx2= max (seg[lc].mx2 , seg[rc].mx2);
    seg[ind].mn2= min (seg[lc].mn2 , seg[rc].mn2);
    seg[ind].ans= max (seg[lc].ans , seg[rc].ans);
    seg[ind].ans= max (seg[ind].ans, seg[lc].mx1- seg[rc].mn1);
    seg[ind].ans= max (seg[ind].ans, seg[rc].mx2- seg[lc].mn2);
}
void solve() {
    int n,q;cin>>n>>q;
    for (int i=0 ;i<n;i++) cin>>a[i];
    build (0,0,n-1);
    cout << query() <<"\n";
    while (q--) {
        int id ,val; cin>>id >>val; id--;
        update (0,0,n-1 ,id,val);
        cout << query () <<"\n";
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