#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

set <pair <pair <int, int>, string> > st;
map <string, pair <int, int> > mp;

pair <pair <int, int>, string> ans;

void in()
{
    //ifstream cin("2033.in");
    for (int i = 1; i <= 6; i++)
    {
        string name, dev, h;
        cin >> name;
        int cost;
        cin >> dev;
        cin >> cost;
        mp[dev].first++;
        //cout << name <<  " " <<dev << " " << cost << " \n";
        //cout  <<dev << " " << mp[dev].first << "\n";
        if (mp[dev].second != 0) mp[dev].second = min(mp[dev].second,cost);
        else   mp[dev].second = cost;
    }
}

void solution()
{
  set <pair <pair <int, int>, string> >:: iterator iter;
  st.insert(make_pair(make_pair(0,0), "ad"));
  iter = st.begin();
  for (map <string, pair <int, int> >:: iterator it = mp.begin(); it != mp.end(); it++)
  {
      st.insert(make_pair(make_pair((it->second).first, (it->second).second), it->first));
      iter++;
      //cout << (*iter).first.first << " " << (*iter).first.second << " " << (*iter).second << "\n";
  }
  set <pair <pair <int, int>, string> >:: reverse_iterator iterat;
  int ch = (*st.rbegin()).first.first;
  for(iterat = st.rbegin(); iterat != st.rend(); iterat++)
  {
     if ((*iterat).first.first == ch)  ans = (*iterat);
  }
}

void out()
{
    //ofstream cout("2033.out");
    cout << ans.second << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
