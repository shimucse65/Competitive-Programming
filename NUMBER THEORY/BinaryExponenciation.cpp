#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7 ;
#define int long long 

//recursive method 
int big_mod (int a,int b)
 {
    if (b==0) return 1;
    int res=big_mod (a,b/2);
    if (b&1) return a*(res*1ll*res) %mod;
    else return  (res*1ll*res)%mod;
 }

 //iterative method (jodi a,b,M er value 1e9 er moddhe hoy)
 int big_mod (int a,int b)
  {
    int ans=1;
    while (b)
     {
        if (b&1) ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b=b>>1;
     }
     return ans;
  }


  
  /*jodi a er value onk beshi hoy (1e18)
  agei mod kore choto kore nibo */
   int big_mod (int a,int b)
  {
    a%=mod; 
    int ans=1;
    while (b)
     {
        if (b&1) ans=(ans*1ll*a)%mod;
        a=(a*1ll*a)%mod;
        b=b>>1;
     }
     return ans;
  }


//jodi mod er value onek boro hoy ba onek boro 2 ta number 
//multiply korte hoy tahole binary multiplication 
int  binarymultiply (int a,int b)
 {
    int ans=0;
    while (b>0)
     {
        if (b&1)
         {
            ans=(ans+a)%mod;
         }
         a=(a+a)%mod;
         b>>=1;
     }
     return ans;
 }



int big_mod (int a,int b)
  {
    int ans=1;
    while (b)
     {
        if (b&1) ans=binarymultiply (ans,a);
        a=binarymultiply (a,a);
        b=b>>1;
     }
     return ans;
  }

//when b is large : a^b %M= a^ (b mod phi (M)) %M 
//when M is prime phi(M)=M-1
signed  main()
  {
    int a,b;cin>>a>>b;
    cout<<big_mod (a,b);
  }










































