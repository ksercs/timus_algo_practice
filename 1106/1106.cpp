#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int n, ans, p = 1, fl, ch;

vector <vector <int> > gr;
vector <int> t[3];

int d[100+15];

set <int> st;

queue <int> q;

void out()
{
    //ofstream cout("1106.out");
    if (fl != 1)
    {
        cout << t[0].size() << "\n";
        for (int i = 0; i < t[0].size(); i++)
        {
            cout << t[0][i] << " ";
        }
    }
    else  cout << "0\n";
}

void bfs()
{
    while(!q.empty())
    {
        int v = q.front();
        if (gr[v].size()==0) {fl = 1; out(); exit(0);}
        st.insert(v);
        for (int i = 0; i < gr[v].size(); i++)
        {
            int to = gr[v][i];
            if (st.count(to)) continue;
            t[d[v]].push_back(to);
            st.insert(to);
            q.push(to);
            d[to]=(d[v]+1)%2;
        }
        q.pop();
    }
}

void in()
{
    //ifstream cin("1106.in");
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        int a = -1;
        while(a != 0)
        {
            cin >> a;
            gr[i].push_back(a);
        }
        gr[i].resize(gr[i].size()-1);
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (!st.count(i)) {d[i] = 0; q.push(i); bfs();}
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
