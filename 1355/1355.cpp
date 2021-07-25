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

const int MAXN = 9592;

int smp[MAXN+15];
int u[(int)1e5+15];
int t, a, b, res;
VEC <int> ans;

void sol(int L, int R)
{
    int ch = R/L;
    for (int i = 0; i < MAXN; ++i)
        while (!(ch % smp[i])){
            ++res;
            ch /= smp[i];
        }
    if (ch != 1) ++res;
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> t;
    ans.resize(t);
    int ind = 0;
    for (int i = 2; i < (int)1e5; ++i)
        if (!u[i]){
            smp[ind++] = i;
           // cout << i << "\n";
            for (LL j = 1LL*i*i; j < (int)1e5; j += i)
                u[j] = 1;
        }
    for (int i = 0; i < t; ++i){
        cin >> a >> b;
        if (b%a) continue;
        sol(a, b);
        ans[i] = res+(res>0 || a == b);
        res = 0;
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
