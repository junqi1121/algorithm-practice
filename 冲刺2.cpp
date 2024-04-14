#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int flag=0;
	for(auto x:s)
	{
		if(x=='Q')
		{
			flag=0;
			cout<<x;
			continue;
		}

		if(!flag)
		{
			cout<<x;
			flag=1;
		}
		
	}
	return 0;
}
