#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_SIZE = 25000 + 5;

int m, ind, maks;
int mass[MAX_SIZE];

vector <int> ans;

void in()
{
    cin >> m;
    int a;
    while(a != -1)
    {
        cin >> a;
        mass[ind] = a;
        ind++;
    }
}

void solution()
{
    for (int i = 0; i <= ind-m-1; i++)
    {
        maks = mass[i];
        for (int g = i+1; g < i+m; g++)
        {
            maks = max(maks, mass[g]);
        }
        ans.push_back(maks);
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
    solution();
    out();
return 0;
}
