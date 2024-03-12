#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 2010,M = 2010;
int n,m;
int a[N][N];
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=m;i++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		a[x1][y1]+=1;
		a[x2+1][y1]-=1;
		a[x1][y2+1]-=1;
		a[x2+1][y2+1]+=1;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			a[i][j]= a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
			if(a[i][j] &1) cout<<1;
			else cout<<0;			
		}
		cout<<endl;
	}
}
