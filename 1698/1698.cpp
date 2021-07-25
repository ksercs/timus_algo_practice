#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int s, f, n, ans;
string s1="1", f1="1";

void test2()
{
    int x, x2;
    bool equal;
    for (int i = s; i < f; i++)
    {
        x = i;
        x2 = i*i;
        equal = true;
        while (x > 0)
        {
            if ((x % 10) != (x2 % 10))
            {
                equal = false;
                break;
            }
            x /= 10;
            x2 /= 10;
        }

        if (equal)
        {
            ans++;
        }
    }
}

void in()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      s1+='0';
      f1+='0';
  }
  f1+='0';
}

void solution()
{
    s = atoi( s1.c_str() );
    f = atoi( f1.c_str() );
}

void out()
{
  cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
