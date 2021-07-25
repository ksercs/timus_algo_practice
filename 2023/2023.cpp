#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ans, nw = 1;

set <string> st1;
set <string> st2;
set <string> st3;

string str;

void in()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (st1.count(str) == 1) {ans += abs(nw - 1); nw = 1;}
        if (st2.count(str) == 1) {ans += abs(nw - 2); nw = 2;}
        if (st3.count(str) == 1) {ans += abs(nw - 3); nw = 3;}
    }
}

void solution()
{
    st1.insert("Alice");
    st1.insert("Ariel");
    st1.insert("Aurora");
    st1.insert("Phil");
    st1.insert("Peter");
    st1.insert("Olaf");
    st1.insert("Phoebus");
    st1.insert("Ralph");
    st1.insert("Robin");
    st2.insert("Bambi");
    st2.insert("Belle");
    st2.insert("Bolt");
    st2.insert("Mulan");
    st2.insert("Mowgli");
    st2.insert("Mickey");
    st2.insert("Silver");
    st2.insert("Simba");
    st2.insert("Stitch");
    st3.insert("Dumbo");
    st3.insert("Genie");
    st3.insert("Jiminy");
    st3.insert("Kuzko");
    st3.insert("Kida");
    st3.insert("Kenai");
    st3.insert("Tarzan");
    st3.insert("Tiana");
    st3.insert("Winnie");
}

void out()
{
  cout << ans << "\n";
}

int main()
{
    solution();
    in();
    out();
return 0;
}
