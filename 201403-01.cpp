#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 500+10,M = 3000; 
int n;
int a;
int ha[M];
int main()
{
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(ha[-a+1500])
			ans++;
		ha[a+1500]++;
	}
	cout<<ans;
	return 0;
} 
