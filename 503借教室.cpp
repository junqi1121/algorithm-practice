#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e6+10,M = 1e6+10;
int n,m;
int r[N];
int s[N],t[N],d[N];
long long b[N];//²î·ÖÊý×é


bool check(int x)
{
	for(int i = 1;i<=n;i++)
	{
		b[i] = r[i]-r[i-1];
	}
	for(int i = 1;i<=x;i++)
	{
		b[s[i]]-=d[i];
		b[t[i+1]+1]+=d[i];
	}
	for(int i = 1;i<=n;i++)
	{
		b[i]+=b[i-1];
		if(b[i]<0) return 0;
	}
	return 1;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i]; 
	}
	for(int i=1;i<=m;i++)
	{
		cin>>d[i]>>s[i]>>t[i];
	}
	int ll = 1,rr = m;
	while(ll<rr)
	{
		int mid = ll + rr >> 1;
		if(check(mid)) ll = mid+1;
		else rr = mid;
	}
	if(check(m)) puts("0");
	else{
		puts("-1");
		cout<<rr<<endl;
	}
	return 0;
}

