#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10, K = 1e5 + 10;
int a,b;
int main()
{
	for(int i=1;i<=10;i++)
	{
		a+=i;
		b+=(2*i);
	}
	cout<<a+b;
	return 0;
}
