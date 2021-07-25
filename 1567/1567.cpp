#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int ans;
int mass[1000];

string str;

void in()
{
  //ifstream cin("a.in");
  getline(cin, str);
}

void solution()
{
  mass[' '-'0'+100] = 1; //cout << ' '-'0'+100 << " ";
  mass['.'-'0'+100] = 1; //cout << '.'-'0'+100 << " ";
  mass[','-'0'+100] = 2; //cout << ','-'0'+100 << " ";
  mass['!'-'0'+100] = 3; //cout << '!'-'0'+100 << " ";
  int ch = 0;
  //cout << "\n";
  for (int i ='a'-'0'+100; i <= 'z'-'0'+100; i++)
  {
   // cout << i << " ";
    mass[i] = ch+1;
    ch=(ch+1)%3;
  }
  for (int i = 0; i < str.size(); i++)
  {
    ans += mass[str[i]-'0'+100];
  }
}

void out()
{
  //ofstream cout("a.out");
  cout << ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
