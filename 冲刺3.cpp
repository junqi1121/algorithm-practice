#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int num[]={1,0,0,0,0,0,1,0,2,1};
int a,b;
int ans=-1,sum=-1;
int main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		string s = to_string(i);
		int tem=0;
		for(auto x:s)
		{
			tem+=num[x-'0'];
		}
		if(tem>sum)
		{
			sum=tem;
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
