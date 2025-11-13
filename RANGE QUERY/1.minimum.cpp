
//0 based 
#include<bits/stdc++.h>
using namespace std;

int a[100005],seg[4*100005];
void build (int ind,int low,int high)
 {
    if (low==high) 
    {
        seg[ind]=a[low]; return;
    }
    int mid=(low+high)/2;
    build (2*ind+1 ,low ,mid);
    build (2*ind+2,mid+1,high);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
 }
 int query (int ind ,int low ,int high,int l,int r)
  {
     if (l<=low && r>=high) return seg[ind];
     if (r<low ||l>high) return INT_MAX;
     int mid=(low+high)/2;
     int left=   query(2*ind+1 ,low ,mid,l,r);
     int right=  query (2*ind+2,mid+1,high,l,r);
     return min (left,right);

  }
  void update (int ind,int low,int high,int pos,int val)
   {
    if (low==high)
     {
        a[low]=val;
        seg[ind]=val; return ;
     }
    int mid=(low+high)/2;
    if (pos<=mid)  update(2*ind+1 ,low ,mid,pos,val);
    else update (2*ind+2,mid+1,high,pos ,val);
    seg[ind]=min (seg[2*ind+1],seg[2*ind+2]);

   }

int main()
 {
    int cs=1;
    int t;cin>>t;
    while (t--)

   {
       int n;cin>>n;
        int q;cin>>q;
        for (int i=0;i<n;i++)cin>>a[i];
        build (0 ,0 ,n-1);
        for (int i=0;i<20;i++) cout<<seg[i]<<" ";
        cout<<"Case "<<cs++<<":"<<"\n";

        while (q--)
      {
        int l,r;cin>>l>>r;
        l-- ,r--;
        int ans= query (0,0,n-1,l,r);
        cout<<ans<<"\n";
       }
   }
     
 }

 //0 based