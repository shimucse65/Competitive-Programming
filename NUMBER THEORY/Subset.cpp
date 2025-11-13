#include<bits/stdc++.h>
using namespace std;

vector <vector <int>> ans (vector <int >&nums)
 {
     int n=nums.size();
     vector <vector<int>>ans;
     int ct = 1<<n;
     for (int mask=0; mask < ct; mask++)
      {
          vector <int>sub;
          for (int i= 0 ; i < n; i++)
           {
               if ( (mask & (1<<i) ) != 0) 
               sub.push_back (nums[i]);
           }
           ans.push_back (sub);
      }
      return ans;
 }
 int main()
  {
      int n;cin>>n;
      vector <int>nums(n);
      for (int i=0;i<n;i++) cin>>nums[i];
      auto res=ans (nums);
      for (auto it :res)
       {
           for (auto el:it) cout<<el<<" ";
           cout<<"\n";
       }
  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 