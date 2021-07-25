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

const int MAXN = 105, INF = (int)1e6;

int n, k, ans, tr;
int inTree[MAXN], w[MAXN];
VEC <VEC < PII > > gr;
set < PII > st;
set <int> r;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> k;
    gr.resize(n+1);
    for (int i = 0; i < k; ++i){
        int a;
        cin >> a;
        r.insert(a);
        tr++;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            int c;
            cin >> c;
            gr[i].PB(MP(j,c));
        }
}

void solution()
{
    for (int i = 1; i <= n; ++i){
        if (!r.count(i)) w[i] = INF;
        st.insert(MP(w[i], i));
    }
    //while (tr < n)
    for (int i = 0; i < n; ++i)
    {
        PII p = (*st.begin());
        int v = p.SS, c = p.FF;
        if (!inTree[v]) tr++;
        inTree[v] = 1;
        st.erase(st.begin());
        for (int j = 0; j < gr[v].SZ; ++j){
            int to = gr[v][j].FF,
                cost = gr[v][j].SS;
            if (cost < w[to] && !inTree[to]){
                st.erase(MP(w[to],to));
                w[to] = cost;
                st.insert(MP(w[to],to));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        ans += w[i];
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
