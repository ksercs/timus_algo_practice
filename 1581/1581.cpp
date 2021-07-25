#include <iostream>
#include <map>

using namespace std;

int n, tmp, ch;

int mass[12];
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      cin >> ch;
      mass[ch]++;
      if (i !=0 && tmp != ch) {cout << mass[tmp] << " "<< tmp << " "; mass[tmp] = 0;}
      tmp = ch;
  }
  cout << mass[ch] << " " << ch << "\n";
  return 0;
}
