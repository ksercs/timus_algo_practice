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

const int MAXN = 105;

int n, answer;
int u[MAXN];
VEC < VEC <int> > gr;
VEC <int> ans;

void DFS(int v)
{
    u[v] = 1;
    if (gr[v].SZ == 0){
        answer++;
        ans.PB(v);
        return;
    }
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        if (!u[to])
            DFS(to);
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            int c;
            cin >> c;
            if (c){
                 gr[j].PB(i);
            }
        }
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        if (!u[i]) DFS(i);
}

void out()
{
    //ofstream cout("output.txt");
    cout << answer << "\n";
    for (int i = 0; i < answer-1; ++i)
        cout << ans[i] << " ";
    cout << ans[answer-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
