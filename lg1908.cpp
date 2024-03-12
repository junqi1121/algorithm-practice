#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5e5+10;
int n;
int a[N];
int res;
int b[N];
void merge_sort(int l,int r)
{
	if(l>=r) return;
	
	int mid = l+r >>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i = l,j=mid+1,k = l;
	while(i<=mid && j<=r)
	{
		if(a[i]<=a[j]) b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			res += (mid-i+1);
		}
	}
	while(i<=mid) 
	{
		b[k++] = a[i++];
	}
	
	while(j<=r) 
	{
		b[k++] = a[j++];
	}
	for(int i = l;i <= r;i++) a[i] = b[i];
}
int main()
{
	cin>>n;
	for(int i = 0;i < n;i++) cin>>a[i];
	merge_sort(0,n-1);
	cout<<res;
	return 0;
}
