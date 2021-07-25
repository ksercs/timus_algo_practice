#include <iostream>

using namespace std;

int n, ans;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    ans += (a/2);
  }
  if (ans%2) cout <<"Daenerys\n";
  else cout <<"Stannis\n";
}
