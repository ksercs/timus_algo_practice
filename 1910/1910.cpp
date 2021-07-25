#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ans, ans_ind;
int mass[1000000+5];

void in()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      cin >> mass[i];
  }
}

void solution()
{
    for (int i = 0; i < n-2; i++)
    {
        if (mass[i] + mass[i+1] + mass[i+2] > ans) {ans = mass[i] + mass[i+1] + mass[i+2]; ans_ind = i+1;}
    }
}

void out()
{
  cout << ans << " " << ans_ind+1 << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
