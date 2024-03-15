#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 1000000

//\operatorname*{gcd}(\sum_{i=1}^{n}i,\prod_{i=1}^{n}i)

ll i,j,k,n,m,t,res=1;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	k=n*(n+1)/2;
	for(i=2;i<=n;i++){
		j=gcd(k,i);
		k/=j; res*=j;
	}
	cout<<res;
}
