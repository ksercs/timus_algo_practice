#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 115;

int n, answer, c;
int col[MAX_SIZE];

vector <vector <int> > gr;

queue <int> q;

void BFS()
{
    while (!q.empty())
    {
        int v = q.front();
        if (col[v]==1) c =2;
        else c=1;
        for (int i = 0; i < gr[v].size(); i++)
        {
            int to = gr[v][i];
            if (col[to] == 0)
            {
                col[to]=c;
               // cout << to << " " << col[to] <<"\n";
                q.push(to);
            }
            if (col[to] != 0 && col[to]!= c)
            {
                answer = -1;
            }
        }
        q.pop();
    }
}

void in()
{
    cin >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
       // cout <<"1\n"; system("PAUSE");
        while(1)
        {
            int NB;
           // cout <<"  2\n\n";
            cin >> NB;
           // cout << "NB=" <<NB << "\n";
            if (NB == 0) {/*cout <<"--BREAK--\n";*/break;}
            gr[i].push_back(NB);
            gr[NB].push_back(i);
        }
    }
}

void solution()
{
    col[1] = 1;
    q.push(1);
    BFS();
}

void out()
{
    if (answer != -1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << col[i]-1;
        }
        cout << "\n";
    }
    else cout <<"-1\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
