#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char tem[] = {'2','0','2','3'};
int check(string a)
{
	int i = 0;
	for(auto x:a)
	{
		if(x==tem[i])
			i++;
		if(i==4)
			return 1;
	}
	return i==4;
	
}
int main()
{
	int ans = 0;
	for(int i=12345678;i<98765432;i++)
	{
		string a = to_string(i); 
		ans += check(a);
	}
//cout<<check("2032");
//cout<<check("20193213");
	cout<<ans;
	
}
