#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int h, w, n, pg=1, ln, sm;

string str;

vector <int> wrd;

void in()
{
    //ifstream cin ("a.in");
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        wrd.push_back(str.size());
        //cout << str.size() << "\n";
    }
}

void solution()
{
    while (!wrd.empty())
    {
       //cout << wrd[0] << "\n";
       if (sm + wrd[0] == w) {ln++; sm = 0;}
       else {
                if (sm + wrd[0] > w) {
                                        if (wrd[0] == w) {ln+=2; sm = 0;}
                                        else             {ln++; sm = wrd[0]+1;}
                                     }
                else {sm += wrd[0] + 1;}
            }
       //if (sm == w) {sm = 0; ln++;}
       if (ln == h) {pg++; ln = 0;}
       if (ln > h) {pg++; ln = ln-h;}
       wrd.erase(wrd.begin());
    }
    if (ln == 0 && sm == 0) {pg--;}
}

void out()
{
     //ofstream cout ("a.out");
     cout << pg << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
