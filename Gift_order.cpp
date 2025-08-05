#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 2e5 + 10;
ll n;
#define lc 2*ind+1 
#define rc 2*ind+2 
int arr[N];

struct node
{
    ll a,b,c,d,e;
};
node seg[4*N];

void build(ll ind, ll low, ll high)
    {
        if (low==high)
        {
            seg[ind].a=arr[low]+(low+1);
            seg[ind].b=arr[low]+(low+1);
            seg[ind].c=arr[low]-(low+1);
            seg[ind].d=arr[low]-(low+1);
            seg[ind].e=0;               
            return;
        }
        ll mid=(low+high)/2;
        build(lc,low,mid);
        build(rc,mid+1,high);

        seg[ind].a=max(seg[lc].a,seg[rc].a);
        seg[ind].b=min(seg[lc].b,seg[rc].b);
        seg[ind].c=max(seg[lc].c,seg[rc].c);
        seg[ind].d=min(seg[lc].d,seg[rc].d);
        seg[ind].e=max(seg[lc].e,seg[rc].e);

        seg[ind].e=max(seg[ind].e,seg[lc].a-seg[rc].b);
        seg[ind].e=max(seg[ind].e,seg[rc].c-seg[lc].d);
    }

 ll query()
    {
        return seg[0].e;
    }

 void update(ll ind,ll low,ll high,ll i,ll val)
    {
        if (low==high)
        {
            seg[ind].a=val+(low+1);
            seg[ind].b=val+(low+1);
            seg[ind].c=val-(low+1);
            seg[ind].d=val-(low+1);
            seg[ind].e=0;              
            return;
        }
        ll mid=(low+high)/2;
        if (i<=mid)
        {
            update(lc,low,mid,i,val);
        } else 
        {
            update(rc,mid+1,high,i,val);
        }
        seg[ind].a=max(seg[lc].a,seg[rc].a);
        seg[ind].b=min(seg[lc].b,seg[rc].b);
        seg[ind].c=max(seg[lc].c,seg[rc].c);
        seg[ind].d=min(seg[lc].d,seg[rc].d);
        seg[ind].e=max(seg[lc].e,seg[rc].e);
        seg[ind].e=max(seg[ind].e,seg[lc].a-seg[rc].b);
        seg[ind].e=max(seg[ind].e,seg[rc].c-seg[lc].d);
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll t=1;
    cin>>t;

    while (t--)
    {
        ll q;
        cin>>n>>q;
        for (ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        build(0,0,n-1);
        cout<<query()<<"\n";      
        while (q--)
        {
            ll ind,val;
            cin>>ind>>val;
            ind--;
            update(0,0,n-1,ind,val);
            cout<<query()<<"\n";
        }
    }
  
}