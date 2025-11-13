#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;
ll h[N], seg[4*N] ;
ll dp[N] ;

ll Q(int pos,int l,int r,int ql,int qr)
{
    if(l > qr or r < ql)
        return 0;
    if(ql <= l and r <= qr)
        return seg[pos] ;
    int mid = (l + r) / 2;
    return max(Q(pos*2,l,mid,ql,qr), Q(pos*2 + 1,mid+1,r,ql,qr));

}

void update(int pos,int l,int r,int ind, ll val)
{
    if(l == r and r == ind)
    {
        seg[pos] = val; return ;
    }
    if(l > ind or r < ind) return ;
    int mid = (l + r) / 2;

    update(pos*2,l,mid, ind, val);
    update(pos*2+1,mid+1,r, ind, val);
    seg[pos] = max(seg[pos*2], seg[pos*2 + 1]) ;
}
int n;
ll val[N] ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        if(h[i] == 1)
        {
            dp[i] = val[i] ;
            update(1,1,n,h[i],val[i]);
            continue;
        }

        ll here = Q(1,1,n,1,h[i]-1 );
        dp[i] = val[i] + here;
        update(1,1,n,h[i],dp[i]);

    }
    cout << *max_element(dp+1,dp+n+1) ;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;
ll h[N], seg[4*N] ;
ll dp[N] ;

ll Q(int pos,int l,int r,int ql,int qr)
{
    if(l > qr or r < ql)
        return 0;
    if(ql <= l and r <= qr)
        return seg[pos] ;
    int mid = (l + r) / 2;
    return  Q(pos*2,l,mid,ql,qr)+ Q(pos*2 + 1,mid+1,r,ql,qr);

}

void update(int pos,int l,int r,int ind, ll val)
{
    if(l == r and r == ind)
    {
        seg[pos] = val; return ;
    }
    if(l > ind or r < ind) return ;
    int mid = (l + r) / 2;

    update(pos*2,l,mid, ind, val);
    update(pos*2+1,mid+1,r, ind, val);
    seg[pos] = seg[pos*2] + seg[pos*2 + 1];
}
int n;
ll val[N] ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        if(h[i] == 1)
        {
            dp[i] = val[i] ;
            update(1,1,n,h[i],val[i]);
            continue;
        }

        ll here = Q(1,1,n,1,h[i]-1 );
        dp[i] = val[i] + here;
        update(1,1,n,h[i],dp[i]);

    }
    cout << *max_element(dp+1,dp+n+1) ;
    return 0;
}


