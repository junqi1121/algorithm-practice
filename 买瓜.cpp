// ��֦��������Ϊ�˼�֦�࿪��һ�����������������֮Ϊ�˼�֦����
// �ɶ��lqb������Ҫ�úü�֦Ŷ���� 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 30+10;
int n,m;
double a[N];
double ssum[N];
int ans=0x3f3f3f3f; 
void dfs(int x,int sum,double pri)
{
	// ��x���ϣ� Ŀǰ����sum�Σ� Ŀǰ��������pri
	if(pri>=m&&pri<=m)
	{
		ans = min(ans,sum);
		return;
	}
	
	if (pri>m)	return;
	
	if(sum>=ans) 	return;
	
	if(pri+ssum[x+1]<m) return;
	
	if(x<n)
	{
		dfs(x+1,sum,pri+a[x+1]);
		dfs(x+1,sum+1,pri+a[x+1]/2);
		dfs(x+1,sum,pri);
	}
}
bool cmp(double a,double b)
{
  return a>b;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
  	sort(a+1,a+1+n,greater<>());
  	
  	for(int i=n;i>=1;i--)
  		ssum[i] = a[i]+ssum[i+1];
  	
	dfs(1,0,a[1]); // ��һ����
	dfs(1,1,a[1]/2); // ����
	dfs(1,0,0); // ���� 
	
	if(ans==0x3f3f3f3f) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
} 
