#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check (int x,int y ,int z ,int i ,int j,int h) {
    if (i>x ||j>x ||h >x)  return false ;
     if (i>y ||j>y ||h >y)  return false ;
      if (i>z ||j>z ||h >z)  return false ;
      return true ;
}


void solve() {
  int x,y,z,k;cin>>x>>y>>z>>k;
  int  mx=0 ;
  
  for (int i=1 ;i<=2000;i++) {
      for (int j=1 ;j<=2000;j++) {
          int h= k/(i*j);
          if (check(x,y,z,i ,j,h)) {
             // cout<<i<<" "<<j<<" "<<h<<"\n";
              int ans= (x-i+1 )*(y-j+1)*(z-h+1) ;
              mx= max (mx ,ans);
              //cout<<mx<<" ";
          }
      }
  }
  cout<<mx<<"\n";
 
}

 signed main ()
  {
   
      int t;cin>>t;
      while (t--)
       {
           solve ();
       }
  }

















