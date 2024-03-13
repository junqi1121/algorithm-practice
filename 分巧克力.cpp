#include<iostream> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10,K = 1e5+10;
int k,n;
int h[N],w[N];
bool check(int x)
{
	int count = 0;
	for(int i = 1;i<=n;i++)
	{
		if(h[i]<x||w[i]<x)
			continue;
		count+= (h[i]/x)*(w[i]/x);
	}
	
	return count>=k;
}
int main()
{
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
		cin>>h[i]>>w[i];
	int l = 1,r = 1e5+10;
	while(l<r)
	{
		int mid = l+r+1 >>1;
		if(check(mid)) l= mid;
		else r = mid-1;
	}
	cout<<r;
	return 0;
}
