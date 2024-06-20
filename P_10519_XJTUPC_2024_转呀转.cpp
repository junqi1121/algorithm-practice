#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double x, y;
double t, v;
double pi = acos(-1.0);
int main()
{
    scanf("%lf%lf%lf%lf", &x, &y, &t, &v);
    x = fabs(x), y = fabs(y);
    double alpha = t * v * 2 * pi;
    double d = sqrt(x * x + y * y);
    double theta = acos(x / d) + alpha;
    double xx = d * cos(theta), yy = d * sin(theta);
    double ans = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    printf("%.12f", ans);
    return 0;
}