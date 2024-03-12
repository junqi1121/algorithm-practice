#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<set>
#include<unordered_map>
#define gkd ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N=2500+10,M = 500+10;
int n,m;
string exp;
struct USER{
	int dn;
	unordered_map<int,int> ss;
}user[N];
int trans(string x)
{
	int sum = 0;
	for(auto i:x)
	{
		sum *= 10;
		sum += (i-'0');
	}
	return sum;
}
set<int> solve(string exp)
{
	set<int> ret;
	//如果是组合表达式  依据符号拆分
	if(exp[0]=='&')
	{
		int r;
		stack<int> st;
		for(int i=1;i<exp.size();i++)
		{
			if(exp[i]=='(')
				st.push(i);
			if(exp[i]==')')
			{
				st.pop();
				if(st.empty())
				{
					r = i;
					break;
				}
			}	
		}
		auto left = solve(exp.substr(2,r-2));
		auto right = solve(exp.substr(r+2,exp.size()-r-3));
//		for(int i=1; i<=n; i++)
//		{
//			if(left.count(i)&&right.count(i))
//			{
//				ret.insert(i);
//			}
//		}
		for(auto x:left)
		{
			if(right.count(x))
				ret.insert(x);
		}

		return ret;
	}
	if(exp[0]=='|')
	{
		//exp前、exp后
		//再合并  (ajkd(f(h)a)sd)(ajhf)
		
		//表达式匹配 
		int r;
		stack<int> st;
		for(int i=1;i<exp.size();i++)
		{
			if(exp[i]=='(')
				st.push(i);
			if(exp[i]==')')
			{
				st.pop();
				if(st.empty())
				{
					r = i;
					break;
				}
			}	
		}
		auto left = solve(exp.substr(2,r-2));
		auto right = solve(exp.substr(r+2,exp.size()-r-3));
//		for(int i=1;i<=n;i++)
//		{
//			if(left.count(i)||right.count(i))
//			{
//				ret.insert(i);
//			}
//		}
		for(auto x:left)
		{
			ret.insert(x);
		}
		for(auto x:right)
		{
			ret.insert(x);
		}
		return ret;
	} 
	
	//如果是原子表达式 fun1
	int a=-1,b=-1;
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]==':')
			a = i;
		if(exp[i]=='~')
			b = i;
	}

//	cout<<a<<' '<<b;
	if(a!=-1)
	{
		int l = trans(exp.substr(0,a)),r = trans(exp.substr(a+1,exp.size()-a-1));
//		cout<<"l: "<<l<<" r: "<<r;
		for(int i=1;i<=n;i++)
		{
			if(user[i].ss.count(l)&&user[i].ss[l]==r)
				ret.insert(user[i].dn);
		}
	}
	if(b!=-1)
	{
		int l = trans(exp.substr(0,b)),r = trans(exp.substr(b+1,exp.size()));
		for(int i=1;i<=n;i++)
		{
			if(user[i].ss.count(l)&&user[i].ss[l]!=r)
				ret.insert(user[i].dn);
		}

	}
	return ret;
}
int main()
{
	gkd;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>user[i].dn>>b;
		user[i].dn=a;
		for(int j=1;j<=b;j++)
		{
			int mm,nn;
			cin>>mm>>nn;
			user[i].ss[mm]=nn;
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>exp;
		for(auto x: solve(exp))
		{
			cout<<x<<' ';
		}
		cout<<endl;
	}
	return 0;
} 

