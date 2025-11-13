#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int spf [N];
void  seive () 
 {
     for (int i=2;i<N;i++) spf[i]=i;
     for (int i=2;i<N;i+=2)
      {
        spf[i]=2;
      }
       for (int i=3;i*i<N;i++)
        {
            if (spf[i]==i)
             {
                for (int j=i*i;j<N;j+=i)
                 {
                    if (spf[j]==j)
                     {
                       spf[j]=i; 
                     }
                 }
             }
        }
     
 }
vector <int> generate (int n)
 {
    vector <int>ans;
    while (n!=1)
     {
        ans.push_back (spf[n]);
        n/=spf[n];
     }
     return ans;
 }
 int main()
  {
   
    seive ();
    int n;cin>>n;
    vector <int>ans=generate(n);
    for (auto it :ans) cout<<it<<" ";
  }
















