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

const int MAXN = 50000 + 15;

int n;
int MINans [MAXN], MAXans[MAXN];

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    VEC < PII > p;
    int fl = n%2;
    p.resize(n/2+fl+1);
    for (int i = 1; i <= n/2+fl; ++i)
        p[i] = MP(i, n+1-i);
    MINans[1] = p[1].FF;
    MINans[2] = p[1].SS;
    int ind = 3;
    for (int i = 2; i <= n/2+fl; ++i){
        if (i%2)    MINans[ind] = p[i].SS;
        else        MINans[ind] = p[i].FF;
        ++ind;
    }
    for (int i = n/2; i >= 2; --i){
        if (i%2)    MINans[ind] = p[i].FF;
        else        MINans[ind] = p[i].SS;
        ++ind;
    }
    MAXans[1] = 1;
    ind = 2;
    for (int i = 2; i <= n; i += 2){
        MAXans[ind] = i;
        ++ind;
    }
    for (int i = n-(!(n%2)); i >= 3; i -= 2){
        MAXans[ind] = i;
        ++ind;
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 1; i < n; ++i)
        cout << MINans[i] << " ";
    cout << MINans[n] << "\n";
    for (int i = 1; i < n; ++i)
        cout << MAXans[i] << " ";
    cout << MAXans[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
