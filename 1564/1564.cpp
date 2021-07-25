#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ifstream cin ("a.in");
    ofstream cout ("a.out");
    for (int i = 1; i <= 1e18; i++)
    {
        int ch;
        while (i > 0)
        {
            ch = i%10;
            if (ch == 1) {cout << i << ", ";}
            i/=10;
        }
    }
return 0;
}
