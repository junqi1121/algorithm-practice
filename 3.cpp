#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double x,r;
double my_abs(double a){
	if(a<0) a = -a;
	return a;
}
int main(){
	cin>>r>>x;
	double s = x/r;
	double ans = my_abs(x*(1/cos(s)-1));
//	cout<<ans;
	printf("%llf",ans);
	return 0;
}
