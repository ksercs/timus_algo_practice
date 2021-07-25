#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

string str;

int ost_del7(string ch)
{
    int ost = 0;
    for (int c = 0; c < ch.size(); c++)
    {
        ost = ((ch[c]-'0')+(ost*10))%7;
    }
    return ost;
}

void in()
{
    cin >> str;
}

void solution()
{
}

void out()
{
    cout << ost_del7(str) << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
