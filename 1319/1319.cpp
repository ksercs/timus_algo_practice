#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ch = 1;

int mass[110][110];

void in()
{
    //ifstream cin("a.in");
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
           mass[i][j] = 1;
       }
   }
}

void solution()
{
    for (int i = 0; i <= n; i++)
    {
        int ind1 = 1, ind2 = n-i;
        while (mass[ind1][ind2]!=0)
        {
            mass[ind1][ind2] = ch; ch++;
            ind1++; ind2++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ind1 = i+1, ind2 = 1;
        while (mass[ind1][ind2]!=0)
        {
            mass[ind1][ind2] = ch; ch++;
            ind1++; ind2++;
        }
    }
}

void out()
{
    //ofstream cout("a.out");
  for (int i = 1; i <= n; i++)
  {
      for (int j = 1; j <= n; j++)
      {
          cout << mass[i][j] << " ";
      }
      cout << "\n";
  }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
