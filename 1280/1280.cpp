#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back

const int MAX_SIZE = 115;

int n, m, fl = 2, answer = 1;

int used[MAX_SIZE];

vector <vector <int> > gr;
vector <int> ans, giv;

void dfs (int v)
{
	used[v] = 1;
	for (int i=0; i < gr[v].size(); ++i)
	{
		int to = gr[v][i];
        if (used[to]==1) answer = 0;
		if (!used[to]) dfs (to);
	}
	used[v] = 2;
	ans.push_back(v);
}

void topological_sort()
{
	for (int i = 1; i <= n; ++i)
	{
        if (!used[i]) dfs(i);
	}
	reverse (ans.begin(), ans.end());
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        giv.push_back(a);
    }
}

void solution()
{
  topological_sort();
}

void out()
{
    //ofstream cout("output.txt");
    if (answer)
    {
        for (int i = 0; i < max(0, int(ans.size())); i++)
        {
            cout << ans[i] << " " << giv[i] << "\n";
            if (ans[i] != giv[i]) answer = 0;
        }
        //cout << ans[ans.size()-1] << "\n";
        if (answer) cout <<"YES\n";
        else        cout << "NO\n";
    }
    else cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
