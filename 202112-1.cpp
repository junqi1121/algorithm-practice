#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e7+10,M = 1e7+10;
int n,m;
int a[N];
LL ans;
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	
	
	
//	int tem = 0;
//	for(int i = 1;i <= n;i ++)
//	{
//		ans += (i-1)*(a[i]-a[i-1]);
////		cout<<ans<<endl; 
//	}
//	ans += n*(m-a[n]);
//	cout<<ans;


	int r = m/(n+1);
	
	
	return 0;
}

