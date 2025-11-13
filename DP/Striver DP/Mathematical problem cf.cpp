#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define MAX 300005
#define inf INT_MAX
//int a[MAX];

void solve() {
    int n;cin>>n;
    string s;cin>>s ;
    int a[n] ;
    for (int i=0;i<n;i++) a[i]= s[i]-'0' ;
    
    int f=0 ;
    for (int i=0;i<n;i++) if (a[i]==0) f=1 ;
    if (f==1&& n>3) {
        cout<<0<<"\n"; return ;
    }
    if (n==3) {
        if (a[0]==0 ||a[n-1]==0) {
             cout<<0<<"\n"; return ;
        }
    } 
    
    
  
    int mn=INT_MAX;
    
    for (int i=0 ;i<n-1 ;i++){
       int x= a[i]*10+ a[i+1] ;
         int c=i ;
          vector <int>v ;
       for (int i=0 ;i<n;i++) {
        if (i!=c) {
            v.push_back (a[i]);
        }
        else   v.push_back (x) ,i++ ;
        }
       
         int dp[n];
       for (int i=0;i<n;i++) dp[i]=-1 ;
      dp[0]=v[0] ;
      for (int i=1 ;i<v.size();i++) {
        dp[i]= min (dp[i-1]*v[i] ,dp[i-1]+v[i]) ;
      }
      mn=min (mn ,dp[v.size()-1]) ;
    }
   
   cout<<mn <<"\n";
    
  
  
    
}

 signed main ()
  {
     int t;cin>>t;
      while (t--)
       {
           solve ();
       }
  }

















