#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		if(2*x>=n) puts("YES");
		else puts("NO");
	}
	return 0;
}
