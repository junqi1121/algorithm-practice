#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010,M = 30; 
int n,m; 
int w[N][M];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>w[i][j];
	for(int i=1;i<=n;i++)
	{
		int ff=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			int flag = 1;
			for(int k=1;k<=m;k++)
			{
				if(w[j][k]<=w[i][k])
				flag=0;
			}
			if(flag) 
			{
				cout<<j<<endl;
				ff=0;
				break;
			}
		}
		if(ff)
		cout<<0<<endl;
	}
	return 0;
}
