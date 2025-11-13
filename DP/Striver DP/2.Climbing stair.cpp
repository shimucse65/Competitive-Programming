//Climbing stairs :leetcode


#include <bits/stdc++.h>
using namespace std ;
int f (int ind  ,vector <int>&dp) {
    if (ind==0) return 1 ;
    if (ind ==1 ) return 1 ;
    
    if (dp[ind]!=-1) return dp[ind] ;
    
    int one_step=  f(ind-1 ,dp);
    int two_step=  f(ind-2 ,dp);
    
    return dp[ind]=one_step+ two_step ;

}
int main () {
    int n;cin>>n ;
    vector <int >dp (n+1 ,-1);
    cout<<f (n,dp);
}
//TC : O (n) ,SC :O(n)+ O(n)
/*
Input: n = 2
Output: 2

Input: n = 3
Output: 3
*/


