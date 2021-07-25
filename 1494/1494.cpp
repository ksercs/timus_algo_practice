#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

int ch, n;

stack <int> st;

void in()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      int a;
      cin >> a;
      if (a != n-i) {ch = 1;}
  }
}

void solution()
{
    if (ch == 1) {cout << "Cheater\n";}
    else         {cout << "Not a proof\n";}
}

void out()
{

}

int main()
{
    in();
    solution();
    out();
return 0;
}
