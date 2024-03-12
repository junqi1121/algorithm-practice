#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10,L = 1e5+10,C = 1e5+10;
int n,l;
int c[N];
bool check(int x)
{
	int count = 0,num = 0;
	for(int i = 1;i<=n;i++)
	{
		if(c[i]>=x)
		count++;
		if(c[i]==x-1)
		num++;
	}
	return (count>=x)||(count+num>=x&&num<=l);
}
int main()
{
	cin>>n>>l;
	for(int i = 1;i<=n;i++) cin>>c[i];
	int l = 0,r = 1e5+10;
	while(l<r)
	{
		int mid = l+r+1 >>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout<<r;
	return 0;
}
