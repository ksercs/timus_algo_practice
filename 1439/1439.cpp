#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

char s;

int n, m, ch;

vector <int> ans;
vector <int> num;
vector <int>:: iterator tmp;

/*int bin_R(int x, int l, int r)
{
    int mid;
    while (r-l > 0)
    {
        mid = l + (r - l) / 2;
        if (num[mid] < x)   {l = mid;}
        else{
            if (num[mid] > x) {r = mid;}
            else                  {
                                    return mid+1;
                                  }
        }
    }
    if (num[l]==x) {return l+1;}
    if (num[r]==x) {return r+1;}
    if (l == 0) return 0;
    return l+1;
}*/

void in()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> ch;
        if (s == 'L')
        {
            if (num.size()==0) {ans.push_back(ch);}
            else
            {
                sort(num.begin(), num.end());
                //cout <<  bin_R(ch, 0, num.size()-1) << "  YA \n";
                tmp = upper_bound(num.begin(), num.end(), ch);
                ans.push_back(ch + tmp-num.begin());
            }
        }
        else  {num.push_back(ch);}
    }
}

void out()
{
  for (int i = 0; i < ans.size(); i++)
  {
      cout << ans[i] << "\n";
  }
}

int main()
{
    in();
    out();
return 0;
}
