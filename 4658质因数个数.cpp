#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
int main()
{
	cin>>n;
	int sum = 0;
	for(int i = 2; i<=n/i;i++)
	{
		if(n%i==0) {
			sum++;
			while(n%i==0)
				n /= i;
		}
	}
	if(n>1) sum++;
	cout<<sum;
	return 0;
 } 
