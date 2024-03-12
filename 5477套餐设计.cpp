#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110,M = 110;
int n,m;
int a[N];
bool check(int mid)
{
	if(mid==0) return 1;
	int sum = 0;
	for(int i = 1;i<=100;i++)
	{
		if(a[i]) 
		{
			sum += (a[i]/mid);
		}
	}
	return sum >= n;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		int x;
		cin>>x;
		a[x]++;
	}
	int ll = 0,rr = 100;
	while(ll<rr)
	{
		int mid = ll+rr+1 >>1;
		if(check(mid)) ll = mid;
		else rr = mid -1;
	}
	cout<<ll;
	return 0;
	
}
