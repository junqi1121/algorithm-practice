#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<int,int> ha;
int main()
{
	for(int i = 1;i<=5;i++)
	{
		ha[i] = 6*i; 
	}
	for(auto x:ha)
	{
		cout<<x<<endl;
	}
	return 0;
		
} 
