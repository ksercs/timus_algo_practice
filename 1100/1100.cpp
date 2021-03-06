#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 150000 + 5;

int n;

pair <int, pair<int,int> > team[MAX_COUNT];

int used[]={110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110};

void in()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      int a, b;
      cin >> a >> b;
      team[i] = make_pair(b, make_pair(used[b]+1, a));
      used[b]--;
  }
}

void solution()
{
  sort(team, team + n);
}

void out()
{
  for (int i = n-1; i >= 0; i--)
  {
      cout << team[i].second.second << " " << team[i].first << "\n";
  }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
