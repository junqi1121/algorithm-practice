#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 100010;
int n;
long long a[N];
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i <= n; i++) a[i]-=a[1];
	int ans = INF;
	for(int i = 1;i <= n; i++)
	{
		
	}
}
