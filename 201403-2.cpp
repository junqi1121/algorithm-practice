#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int N=10+10;
int n,m;
struct WINDOW{
	int x1,x2,y1,y2;
	int level;
}window[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>window[i].x1>>window[i].y1>>window[i].x2>>window[i].y2;
		window[i].level = i;
	}
	// idx用于设置新点击的窗口的level 
	int idx = n;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		int flag =1;
		vector<int> ret;
		for(int j=1;j<=n;j++)
		{
			if(a>=window[j].x1&&a<=window[j].x2&&b>=window[j].y1&&b<=window[j].y2){
				ret.push_back(j);
				flag = 0;
			}
		}
		if(flag) puts("IGNORED") ;
		else{
			int ans = ret[0];
			for(auto x:ret)
			{
				if(window[ans].level<window[x].level)
					ans = x;
			}
			cout<<ans<<' '<<endl;
			window[ans].level = (++idx);
		}
	}
	return 0;
}
