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

int x, y, ans, t;

int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

int mass[12][12];

vector <int> answer;
void solution()
{
    x = str[0]-'0'-47;
    y = str[1] - '0'+1;
    //cout << x << " " << y << "\n";
    for (int i = 0; i <=11; i++)
    {
        for (int j = 0; j <=11; j++)
        {
            mass[i][j] = 0;
        }
    }
    for (int i = 2; i <=9; i++)
    {
        for (int j = 2; j <=9; j++)
        {
            mass[i][j] = 1;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (mass[x+dx[i]][y+dy[i]] == 1) {ans ++;}
    }
    answer.push_back(ans);
    ans = 0;
}

void in()
{
    cin >> t;
    for (int h = 0; h < t; h++)
    {
      cin >> str;
      solution();
    }
}

void out()
{
   for (int i = 0; i < answer.size(); i++)
   {
       cout << answer[i] << "\n";
   }
}

int main()
{
    in();
    out();
return 0;
}
