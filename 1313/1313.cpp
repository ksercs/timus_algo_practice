#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;

int mass[110][110];

vector <int> ans;

void in()
{
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= n+1; j++)
        {
            mass[i][j] = 0;
        }
    }
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= n; j++)
       {
           cin >> mass[i][j];
       }
   }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        int ind1 = i, ind2 = 1;
        while (mass[ind1][ind2]!=0)
        {
            ans.push_back(mass[ind1][ind2]);
            ind1--; ind2++;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int ind1 = n, ind2 = i;
        while (mass[ind1][ind2]!=0)
        {
            ans.push_back(mass[ind1][ind2]);
            ind1--; ind2++;
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
    solution();
    out();
return 0;
}
