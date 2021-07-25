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

const int MAXN = (int)1e5+15;

int n;
int mass[MAXN];
VEC < pair < PII, int> > v;
VEC < PII > ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    v.resize(n);
    for (int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        v[i-1] = MP(MP(b, a), i);
    }
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = n-1; i >= 0; --i){
        for (int j = v[i].FF.SS; j >=1; --j)
            if (!mass[j]){
                mass[j] = 1;
                ans.PB(MP(v[i].FF.SS, v[i].SS));
                break;
            }
    }
    sort(ans.begin(), ans.end());
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans.SZ << "\n";
    for (int i = 0; i < ans.SZ-1; ++i)
        cout << ans[i].SS << " ";
    cout << ans.back().SS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
