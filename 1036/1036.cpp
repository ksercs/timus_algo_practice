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

int n, m;
LL ans;

map < PII, int > dp;
set <PII> st;

LL dfs_R (int num, int sum)
{
    //cout << num << " " << sum << "\n";
    if (sum < 0) return 0;
    if (st.count(MP(num, sum)))
        return dp[MP(num, sum)];
    /*if (num == 1 && sum < 10 && sum > 0){
        cout << num << " " << sum << "\n";
        dp[MP(num, sum)] = 1;
        return 1;
    }*/
    if (!num){
        if (!sum)
            dp[MP(num, sum)] = 1;
        else dp[MP(num, sum)] = 0;
        st.insert(MP(num, sum));
        return dp[MP(num, sum)];
    }
    LL res = 0;
    for (int i = 0; i < 10; ++i)
        res += dfs_R (num-1, sum-i);
    dp[MP(num, sum)] = res;
    st.insert(MP(num, sum));
    cout << num << " " << sum << " " << res << "\n";
    return res;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
}

void solution()
{
    if (m%2)
        return;
    m /= 2;
    ans = dfs_R(n, m);
    ans *= ans;
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
