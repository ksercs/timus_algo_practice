#include <iostream>

using namespace std;

int x, y, c;

int main()
{
  cin >> x >> y >> c;
  if (c <= x) cout << c << " 0" << "\n";
  else
  {
    if (c <= y) cout << "0 " << c << "\n";
    else
    {
      if (c <= x+y)
      {
        if (x < y) cout << x << " " <<c-x << "\n";
        else       cout << c-y << " " <<y << "\n";
      }
      else cout << "Impossible\n";
    }
  }
}
