#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define afor(i,a,b) for (int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=a;i>=b;i--)
#define print(A,j,k) for(int ii=j;ii<k;ii++)cout<<A[ii]<<" ";cout<<"\n";
#define all(v) v.begin(),v.end()
#define ps cout<<"YES\n";
using namespace std;
int main()
{
	fast
	ll n,m,k,c=0,a[100010];
	cin>>n>>m>>k;
	afor(i,0,n)
	{
		cin>>a[i];
	}
	afor(i,1,n)
	{
		if(a[i]!=0 && a[i-1]!=0)
		{
			if(a[i]%2!=0 && a[i-1]%2==0)
				c++;
			else if(a[i]%2==0 && a[i-1]%2!=0)
				c++;
		}
	}
	if(c>k)
	{
		cout<<"0\n";
		return 0;
	}
	ll ans=1;
	ll r=k-c;
	ll even =m/2;
	ll odd =m/2;
	afor(i,0,n)
	{
		if(a[i]==0)
		{
			if(i!=0 && i!=n-1)
			{
				if(a[i-1]%2==0 && a[i+1]%2==0)
				{
					ans=(ans%mod*odd%mod)%mod;
				}
				else if(a[i-1]%2!=0 && a[i+1]%2!=0)
				{
					ans=(ans%mod*even%mod)%mod;
				}
				else
				{
					ans=(ans%mod*m%mod)%mod;
				}
			}
			else if(i==0)
			{
				if(a[i+1]%2!=0 && a[i+1]!=0)
					ans=(ans*even)%mod;
				else
					ans=(ans*odd)%mod;
			}
			else if(i==n-1)
			{
				if(a[i-1]%2==0)
				{
					ans=(ans*odd)%mod;
				}
				else
					ans=(ans*even)%mod;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}