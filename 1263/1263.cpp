#include <iostream>
#include <map>

using namespace std;

int n, m;

map <int, double> mp;

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int ch;
    cin >> ch;
    mp[ch]++;
  }
  for (int i = 1; i <= n; i++)
  {
    cout.precision(2);
    cout <<fixed << (mp[i])/m*100 << "%\n";
  }
  return 0;
}
