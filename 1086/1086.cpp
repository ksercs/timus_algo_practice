#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w;
int mass[1000000];

vector <int> v, ans;

int main()
{
    cin >>n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (w=2; w<=1000000; w++)
    {
      if (mass[w]==0) {
                          for (int g=w+w; g<=1000000; g=g+w)
                          {
                              mass[g]=1;
                          }
                      }
    }
    for (int i=2; i<=1000000; i++)
    {
        if (mass[i]==0) {ans.push_back(i);}
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans[v[i]-1] << "\n";
    }
    return 0;
}
