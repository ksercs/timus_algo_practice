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

const int MAXN = 100 + 15,
          MAXW = (int)1e5 + 15,
          NOT = -1;

int NPsum, ans, n;
VEC <int> w;
set <int> num;
int16_t dp[MAXN][MAXW];
int p[MAXN][MAXW];

void DP ()
{
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j <= NPsum; ++j){
            dp[i][j] = NOT;
            p[i][j] = NOT;
        }
    for (int  i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int  i = 1; i <= n; ++i)
        for (int j = 1; j <= NPsum; ++j){
            int newW = j - w[i],
                predR = i - 1;
            if (dp[predR][j] != NOT)
                    if (dp[i][j] == NOT){
                        dp[i][j] = dp[predR][j];
                        p[i][j] = p[predR][j];
                    }
            if (newW >= 0)
                if (dp[predR][newW] != NOT) {
                            dp[i][j] = min(max(dp[predR][newW], (int16_t)(dp[i][j]+1)),(int16_t)2);
                            p[i][j] = predR;
                        }
        }
    /*for (int16_t i = 0; i <= n; ++i){
        for (int16_t j = 0; j <= NPsum; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
}

void in()
{
    //ifstream cin("input.txt");
    cin >> NPsum;
    cin >> n;
    w.resize(n+1);
    for (int  i = 1; i <= n; ++i)
        cin >> w[i];
}

void solution()
{
    DP();
    if (dp[n][NPsum] != NOT)
        dp[n][NPsum] == 1 ? ans = 1 : ans = -1;
    if (ans != 1)
        return;
    int  i = n, weight = NPsum;
    for (int  i = 1; i <= n; ++i)
        num.insert(i);
    while (i && weight) {
        if ( p[i][weight] != p[i - 1][weight] ){
            num.erase(i);
            weight -= w[i];
        }
        i--;
    }
}

void out()
{
    //ofstream cout("output.txt");
    if ( ans == 1 )
        for (auto item : num)
            cout << item << " ";
    else
        cout << ans;
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
