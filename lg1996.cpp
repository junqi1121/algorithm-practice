#include<iostream>
#include<algorithm>
using namespace std;
const int  N = 110;
int n,m;
int h[N];
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		h[i] = (i+1)%n;
	}
	h[0] = 1;
	cout<<h[10];
	int count = 0,pre = 0;
	for(int i = h[0];i!=h[i];i++)
	{
		count++;
		if(count==m)
		{
			count=0;
			cout<<i<<' ';
			h[pre] = h[i];
			continue;
		}
		pre = i;
	}
}
