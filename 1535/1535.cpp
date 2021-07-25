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
#include <climits>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 50 + 15;

int n, minsum = INT_MAX, maxsum;
string s;
int u[MAXN];
VEC <int> minv, maxv;
VEC <string> perm;

void dfs_R(int ind)
{
    if (ind == n)
    {
        perm.push_back(s);
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (u[i] == 0)
            {
                u[i] = 1;
                s[ind] = i+'0';
                dfs_R(ind+1);
                u[i] = 0;
            }
        }
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    minv.resize(n+1);
    maxv.resize(n+1);
    for (int i = 1; i <= n; ++i)
        s += " ";
    dfs_R(0);
    /*for (int i = 0; i < perm.SZ; ++i)
        cout << perm[i] << "\n";*/
    for (int i = 0; i < perm.SZ; ++i){
        VEC <int> vec(n+1);
        for (int h = 0; h < perm[i].SZ; ++h)
            vec[(int)(perm[i][h]-'0')] = h+1;
        /*for (int h = 1; h <= n; ++h)
            cout << vec[h] << " ";
        cout << "\n";*/
        int ch = 0;
        for (int j = 2; j <= n; ++j){
            ch += vec[j]*vec[j-1];
        }
        ch += vec[1]*vec[n];
        //cout << ch << "\n";
        if (ch < minsum){
            minsum = ch;
            for (int k = 1; k <= n; ++k)
                minv[k] = vec[k];
        }
        if (ch > maxsum){
            maxsum = ch;
            for (int k = 1; k <= n; ++k)
                maxv[k] = vec[k];
        }
    }
        cout << minsum << " " << maxsum << "\n";
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 1; i < n; ++i)
        cout << minv[i] << " ";
    cout << minv[n] << "\n";
    for (int i = 1; i < n; ++i)
        cout << maxv[i] << " ";
    cout << maxv[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
