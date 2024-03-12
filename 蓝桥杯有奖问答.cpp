#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int ans = 0;
void dfs(int n,int s)
{
	if(n>30)
	{
		if(s==70)
			ans++;
		return;
	}
	if(s==70) ans++;
	if(s==100)
		return;
	dfs(n+1,s+10);
	dfs(n+1,0);
}
int main()
{
	dfs(1,0);
	dfs(1,10); 
	cout<<ans;
	return 0;
}
