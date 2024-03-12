#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N=1e5+10,MOD = 998244353;
int n;
int a;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
    return d;
}
int main()
{
	cin>>n;
	long long sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum+=a;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		int tem = (sum*i)%MOD;
		int d=exgcd(n,tem,x,y);
		while(x<0)
			x+=(tem/d);
		
		while(x>MOD)
			x-=(tem/d);
		cout<<x<<' ';	
	}	
	return 0;
	
}

