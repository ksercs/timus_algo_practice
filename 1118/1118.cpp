#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 3*100000 + 5;

int n, q;

long long zr[MAX_COUNT];

vector <long long> ans;

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> zr[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int ind;
            cin >> ind;
            ans.push_back(zr[ind]);
        }
        if (tp == 2)
        {
            int L, R, d;
            cin >> L >> R >> d;
            for (int g = L; g <= R; g++)
            {
                int index = g;
                int tmp = g;
                while(index <= n)
                {
                    zr[index] += d;
                    index+=tmp;
                }
            }
        }
    }
}

void out()
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    in();
    out();
return 0;
}
