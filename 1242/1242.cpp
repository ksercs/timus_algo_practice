#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int n, lvl;
int used[1000 + 50];

vector <vector <int> > gr1;
vector <vector <int> > gr2;
vector <int> start, ans;

void dfs_up(int v)
{
 // cout << "UP: " << v << "\n";
  used[v] = 1;
  for (int i = 0; i < gr1[v].size(); i++)
  {
      int to = gr1[v][i];
      if (!used[to])
      {
          dfs_up(to);
      }
  }
}

void dfs_down(int v)
{
  //cout << "DOWN: " << v << "\n";
  used[v] = 1;
  for (int i = 0; i < gr2[v].size(); i++)
  {
      int to = gr2[v][i];
      if (!used[to])
      {
          dfs_down(to);
      }
  }
}

void in()
{
   //ifstream cin("1242.in");
   cin >> n;
   start.resize(n+1);
   gr1.resize(n+1);
   gr2.resize(n+1);
   string s1, s2;
   int m1, m2;
   while(s1 != "BLOOD")
   {
       cin >> s1;
       if (s1 != "BLOOD")
       {
           cin >> s2;
           //cout << s1 << " " << s2 << "\n"; system("PAUSE");
           m1 = atoi(s1.c_str());
           m2 = atoi(s2.c_str());
           gr1[m1].push_back(m2);
           gr2[m2].push_back(m1);
       }
   }
   int a;
   while(cin >> a)
   {
       start.push_back(a);
   }
}

void solution()
{
  for (int i = 0; i < start.size(); i++)
  {
      dfs_up(start[i]);
      dfs_down(start[i]);
  }
  for(int i = 1; i <= n; i++)
  {
      if (!used[i])
      {
          ans.push_back(i);
      }
  }
}

void out()
{
    //ofstream cout("1242.out");
    if (ans.size() != 0)
    {
        for (int i = 0; i < ans.size()-1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1] << "\n";
    }
    else cout << "0\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
