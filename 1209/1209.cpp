#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

std::set <int> st;

std::vector <int> ans(1000000);

int n, ind, ch;

void in()
{
    scanf ("%d",n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%d",ind);
        if (st.count(ind)==1) {/*ans.push_back(1);*/printf ("%s \n", "1 ");}
        else              {/*ans.push_back(0);*/ printf ("%s \n", "0 ");}
    }
}

void solution()
{
   // ofstream cout("a.out");
     for (int i = 1; i < 2147483648; i+=ch)
     {
         st.insert(i);
         ch++;
        // cout << i << ", ";
     }
}

void out()
{
    /*for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }*/
}

int main()
{
    solution();
    in();
   // out();
return 0;
}
