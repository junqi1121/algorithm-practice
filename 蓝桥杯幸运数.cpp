#include<iostream>
#include<string>
using namespace std;
int ans = 0;
int main()
{
	for(int k=1;k<=100000000;k++)
	{
		string s = to_string(k);
		if(s.size()%2==1) 
		{
			k*=10;
			continue;	
		}
		int sum=0,odd=0;
		for(int i = 0;i < s.size();i++)
		{
			sum+=(s[i]-'0');
			if(i<s.size()/2)
				odd+=(s[i]-'0');
		}
		if(sum==odd*2)
			ans++;
	}
	cout<<ans;
	return 0;
} 
