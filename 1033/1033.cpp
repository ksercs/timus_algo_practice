#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, ans;

int used[40][40];
char gr[40][40];

int dx[]={1,-1,0,0},
    dy[]={0,0,1,-1};

queue <pair <int, int> > q;

void bfs()
{
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        used[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (gr[nx][ny]=='#') ans++;
            else
            {
                if (!used[nx][ny]) {used[nx][ny] = 1; q.push(make_pair(nx, ny));}
            }
        }
        q.pop();
    }
}

void in()
{
    //ifstream cin("1033.in");
    cin >> n;
    for (int i = 0; i <= n+1; i++)
    {
        for (int g = 0; g <= n+1; g++)
        {
            gr[i][g] = '#';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int g = 1; g <= n; g++)
        {
            cin >> gr[i][g];
        }
    }
}

void solution()
{
    q.push(make_pair(1, 1));
    bfs();
    if (used[n][n]==0) {q.push(make_pair(n,n)); bfs();}
    ans-=4;
}

void out()
{
    //ofstream cout("1033.out");
    cout <<ans*9 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
