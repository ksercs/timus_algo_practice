#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int cnt;
vector <int> dp(60000+15, INT_MAX);
vector <int> sq;

void in()
{
    cin >> cnt;
}

void solution()
{
    dp[0]=0;
    for (int i = 1; i < 60000; i++)
    {
        int q = i*i;
        if (q>60000) break;
        sq.push_back(q);
    }
    for (int i = 0; i <= 60000; i++)
    {
        for (int j = 0; j < sq.size(); j++)
        {
            if (i+sq[j] > 60000) break;
            dp[i+sq[j]] = min(dp[i+sq[j]], dp[i]+1);
        }
    }
}

void out()
{
    cout << dp[cnt] << "\n";
}


int main()
{
    in();
    solution();
    out();
}
