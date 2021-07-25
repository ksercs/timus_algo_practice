#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans, st;

vector <pair <int, int> > ev;

void in()
{
    cin >> n;
    ev.resize(n);
    for (int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        ev[i] = make_pair(s, f);
    }
}

void solution()
{
    sort(ev.begin(), ev.end());
    for (int i = 0; i < ev.size(); i++)
    {
        if (ev[i].first >= st) {ans++; st = ev[i].second+1;}
    }
}

void out()
{
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
