#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define pb push_back
#define SZ size()
#define vec vector

using namespace std;

const int INF = (int)1e9, MAXN = (int)1e3+5;

int n, st, way;
int p[MAXN];
vec <vec <int> > gr;
vec <int> s, ans;

void check(int w)
{
   if (w%2) ans.pb(s[1]);
}

void DFS(int v)
{
    s.pb(v);
    //cout <<"VERTEX:  " << v << endl;
    int v_SZ = gr[v].SZ;
   // if ( !v_SZ ) check(way);
    int nw = 0;
    for (int i = 0; i < v_SZ; i++)
    {
        int to = gr[v][i];
        if (p[to] != -1)
        {
           // cout << to << endl;
            p[to] = -1;
            way++;
            DFS(to);
            way--;
            p[to] = 0;
        }
        else nw++;
    }
    if (nw == v_SZ) check(way);
    p[v] = -1;
    s.pop_back();
}

void in()
{
    ifstream cin("A.in");
    cin >> n >> st;
    gr.resize(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
        gr[b].pb(a);
    }
   /* for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int g = 0; g < gr[i].SZ; g++)
        {
            cout << gr[i][g] << " ";
        }
        cout << endl;
    }*/
}

void solution()
{
  p[st] = -1;
  DFS(st);
  sort(ans.begin(), ans.end());
}

void out()
{
    ofstream cout("A.out");
    if ( !(ans.SZ) ) cout << "First player loses\n";
    else            cout << "First player wins flying to airport " << ans[0] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
