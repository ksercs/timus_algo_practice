#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = (int)1e5+15;

int n, m, cnt, q;
int parent[MAXN], u[MAXN], no[MAXN], size[MAXN];
VEC <VEC <int> > gr;
VEC < PII > ed;
VEC <int> del, ans;

void DFS(int v)
{
    u[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        if (!u[to]){
            u[to] = 1;
            parent[to] = parent[v];
            size[parent[v]]++;
            DFS(to);
        }
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    gr.resize(n+1);
    ed.resize(m);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        //gr[a].PB(b);
        //gr[b].PB(a);
        ed[i] = MP(a, b);
    }
    cin >> q;
    del.resize(q);
    for (int i = 0; i < q; ++i){
        cin >> del[i];
        del[i]--;
        int a = del[i];
        no[a] = 1;
    }
    for (int i = 0; i < m; ++i){
        int a, b;
        if (no[i]) continue;
        a = ed[i].FF;
        b = ed[i].SS;
        gr[a].PB(b);
        gr[b].PB(a);
    }
}

int get_p(int x)
{
    if (parent[x] == x) return x;
    else  return parent[x] = get_p(parent[x]);
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        if (!u[i]) {
            parent[i] = i;
            size[i] = 1;
            DFS(i);
            ++cnt;
        }
    ans.PB(cnt);
    for (int i = q-1; i > 0; --i){
        int a, b, ind;
        ind = del[i];
        a = ed[ind].FF;
        b = ed[ind].SS;
        int d = get_p(a);
        int g = get_p(b);
        if (d != g){
            --cnt;
            if (size[d] > size[g])
                swap(d,g);
            parent[d] = g;
            size[d] += size[g];
        }
        ans.PB(cnt);
        /*for (int j = 1; j <= n; ++j)
            cout << j << " : " << parent[j] << "\n";
        cout << "\n";*/
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = ans.SZ-1; i > 0; --i){
        cout << ans[i] << " ";
    }
    cout << ans[0] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
