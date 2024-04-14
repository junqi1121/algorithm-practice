#include<algorithm>
#include<cstring>
#include<iostream>
#include<utility>
using namespace std;
const int N=1e5+10;
int n;
pair<int,int> a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i].second+a[n+1-i].second!=n+1)
			{
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}


