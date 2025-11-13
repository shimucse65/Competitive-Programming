#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
int  h[N], seg[4*N] ;
int  dp[N] ;int  a[N];

void build (int ind,int low,int high)
 {
    if (low==high) 
    {
        seg[ind]=a[low]; return;
    }
    int mid=(low+high)/2;
    build (2*ind+1 ,low ,mid);
    build (2*ind+2,mid+1,high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
 }
 
int query (int pos,int l,int r,int ql,int qr)
{
    if(l > qr or r < ql)
        return INT_MIN;
    if(ql <= l and r <= qr)
        return seg[pos] ;
    int mid = (l + r) / 2;
    return max(query(pos*2,l,mid,ql,qr), query(pos*2 + 1,mid+1,r,ql,qr));

}

void update(int pos,int l,int r,int ind, int val)
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
//0 based