#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int main()
{
    cin>>n;
    long long sum=0;
    for(int i = 1;i<=n;i++)
    {
        long long x;
        cin>>x;
        sum+=x;
    }
    cout<<n*(n+1)/2-sum;
    return 0;
}