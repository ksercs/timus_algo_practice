#include <iostream>

using namespace std;

int mass[55];
int sum, n;

int main()
{
  cin >> n;
      for(int i=1; i <= n; i++)
          {sum+=i;}
      if(sum%2==0)
          {cout << "black\n";}
      else
          {cout << "grimy\n";}
  return 0;
}
