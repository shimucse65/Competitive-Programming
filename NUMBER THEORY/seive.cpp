#include<bits/stdc++.h>

#define int long long

#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL)

const int N=1e7+10;
using namespace std;
vector<int>v;
void siv()
{
    vector<bool>p(N,true); //true -prime
    p[0]=p[1]=false;
	for(int i=2;i*i<=N;i++)
	{
		if(p[i])
		{
			for(int j=2*i;j<=N;j+=i)
			{
				p[j]=0;
			}
		}
	}
	for(int i=2;i<=N;i++)
    {
        if(p[i]) v.push_back(i);
    }


}
void solve()
{
    int n;cin>>n;
	cout<<v[n-1]<<endl;
}
int32_t main()
{
   FAST;
   siv();
	int t;

	cin>>t;
	while(t--)
	solve();

}
