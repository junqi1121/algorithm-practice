#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD = 1e9+7,N = 1e9+10;
int n;
long long ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans += (n/i) * (long long)i* i;
		ans = ans % MOD;
	}
	cout<<ans;
	return 0; 
 } 
