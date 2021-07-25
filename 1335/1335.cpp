#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

LL n, a, b, c, L, R;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    a = n*n+2*n;
    b = n*n+n;
    c = n*n;
    if (!((b*b+c*c)%a)) swap(a,c);
    if (!((a*a+c*c)%b)) swap(b,c);
}

void out()
{
    //ofstream cout("output.txt");
    cout << a << " " << b << " " << c << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
