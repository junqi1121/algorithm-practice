#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x, y;
double sqr3 = sqrt(3) / 2;
int main()
{
    scanf("%lf%lf", &x, &y);
    printf("%.6f %.6f", (x + y) / 2, sqr3 * (x - y));
    return 0;
}