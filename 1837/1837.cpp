#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <vector>

using namespace std;

const int MAX_COUNT = 300+15;

int n;

map <string, vector <string> > mp;
vector <string>:: iterator iter;
map <string, int> d;
map <string, int> used;

set <string> name;
set <string>::iterator it;

queue <string> q;

void BFS()
{
    while (!q.empty())
    {
        string v = q.front();
        for (iter = mp[v].begin(); iter != mp[v].end(); ++iter)
        {
            string to = *iter;
            if (used[to]==0)
            {
                used[to] = 1;
                q.push(to);
                d[to]= d[v]+ 1;
            }
        }
        q.pop();
    }
}

void in()
{
    //ifstream cin("1837.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        d[s1] = -1;
        d[s2] = -1;
        d[s3] = -1;
        used[s1] = 0;
        used[s2] = 0;
        used[s3] = 0;
        name.insert(s1);
        name.insert(s2);
        name.insert(s3);
        mp[s1].push_back(s2);
        mp[s1].push_back(s3);
        mp[s2].push_back(s1);
        mp[s2].push_back(s3);
        mp[s3].push_back(s1);
        mp[s3].push_back(s2);
    }
}

void solution()
{
  d["Isenbaev"]=0;
  q.push("Isenbaev");
  BFS();
  d["Isenbaev"]=0;
}

void out()
{
    //ofstream cout("1837.out");
   for (it = name.begin(); it != name.end(); it++)
   {
       if (d[*it] == -1) cout << *it << " undefined\n";
       else              cout << *it << " " << d[*it] << "\n";
   }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
