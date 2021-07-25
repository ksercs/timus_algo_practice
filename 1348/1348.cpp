#include <iostream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <cmath>

using namespace std;

double ax, ay, bx, by, cx, cy, len, ans1, ans2;

pair <double, double> ab, ba, ac, bc;

double DP(pair <double, double> p1, pair <double, double> p2)
{
    return p1.first * p2.first + p1.second * p1.second;
}

double CP(pair <double, double> p1, pair <double, double> p2)
{
    return p1.first * p2.second - p1.second * p2.first;
}


void in()
{
    cin >> ax >> ay >>bx >> by >> cx >> cy >> len;
}

void solution()
{
    ax -= cx;
    bx -= cx;
    ay -= cy;
    by -= cy;
    cx = 0; cy = 0;
    ab = make_pair(ax-bx, ay-by);
    ac = make_pair(ax, ay);
    ba = make_pair(bx-ax, by-ay);
    bc = make_pair(bx, by);
    if (DP(ab, ac) > 0 && DP(ba, bc) > 0) ans1 = max(0.0,abs(CP(ab, ac) / hypot(ab.first, ab.second))-len);
    else ans1 = max(0.0, min(hypot(ac.first, ac.second), hypot(bc.first, bc.second))-len);
    ans2 = max(0.0,max(sqrt(ax*ax + ay*ay), sqrt(bx*bx + by*by))-len);
}

void out()
{
  cout <<fixed << setprecision(2) <<ans1 << "\n" << ans2 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
