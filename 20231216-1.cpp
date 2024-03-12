#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
const int N = 1e6+10;
int n;
int m[N];
int tem[N];
int main()
{
	int n = 0;
	cin>>n;
	int a=0,b;
	for(int i = 1;i <= n;i++)
	{
		cin>>b;
		a^=b;
		tem[i]^=tem[i-1]^i;
	}
	for(int i = 1;i <= n;i++)
	{
		a ^= tem[n%i];
		if( (n/i) % 2)
		a ^= tem[i-1];
	}
	cout << a;
	return 0;
}
 
