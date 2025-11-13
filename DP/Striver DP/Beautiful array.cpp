#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define MAX 300005
#define inf INT_MAX
//int a[MAX];

void solve() {
    int n,k;cin>>n>>k;
    int a[n];
    map <int,vector<int>>mp;
    map <int ,int>mp2 ;
    for (int i=0;i<n;i++){
        cin>>a[i]; mp2[a[i]]++ ;
        mp[a[i]%k].push_back (a[i]/k);
    }
    // int odd=0 ;
    // for (auto it :mp2) {
    //     if (it.second&1) odd++ ;
    // }
    // if (odd<2) {
    //     cout<<0<<"\n"; return ;
    // }
   if (n==1) {
       cout<<0<<"\n" ;return ;
   }
   int cnt=0 ;
   for (auto it :mp) if (it.second.size()&1) cnt++ ;
   if (cnt>1) {
       cout<<-1<<"\n"; return ;
   }
    int ans=0 ;
    for (auto it :mp) {
        vector <int>v= it.second ;
        sort (v.begin(),v.end ()) ;
       //for (auto it :v) cout<<it<<" ";cout<<"\n";
        int m=v.size();
       if (m%2==0) {
           for (int i=0;i<m;i+=2) ans+= v[i+1]-v[i] ;
       } 
       else { 
           int pf[n] ,sf[n] ;
           pf[1]=v[1]-v[0] ;
           for (int i=3 ;i<n;i+=2) pf[i]= pf[i-2]+(v[i]-v[i-1]) ;
          for (int i=1 ;i<n;i+=2) cout<<pf[i]<<" ";cout<<"\n";
           
           sf[m-2]= v[m-1]-v[m-2] ;
           for (int i=m-4 ;i>=0 ;i-=2) {
               sf[i]=sf[i+2] + (v[i+1]-v[i]) ;
           }
           int mn=min (sf[1] ,pf[m-2]) ;
           for (int i=2 ;i<n ;i+=2) {
               mn= min (mn ,pf[i-1]+sf[i+1]) ;
           }
           ans+= mn ;
       }
    }
   cout<<ans <<"\n";
    
}

 signed main ()
  {
     int t;cin>>t;
      while (t--)
       {
           solve ();
       }
  }

















