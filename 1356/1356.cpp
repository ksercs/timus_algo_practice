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

const int UP = 5133+2, U = 95+2;
const int MAXN = 9592;
int mass[int(1e5+15)];

int t, n, EX;
int pr[10000];

map <int, int> mp;
VEC <int> ans[25];

void out()
{
    //ofstream cout("output.txt");
    if (EX){
        cout << "\n";
        return;
    }
    for (int i = 1; i <= t; ++i){
        for (int j = 0; j < ans[i].SZ-1; ++j)
            cout << ans[i][j] << " ";
        cout << ans[i].back() << "\n";
    }
}

void solution(int i)
{
    if (mp[n]){
        ans[i].PB(n);
        return;
    }
    int f = 0;
    for (int d = 0; d < MAXN; ++d)
        if (!(n%pr[d])){
            f = 1;
            break;
        }
    if (!f){
        ans[i].PB(n);
        return;
    }
    //cout << "N= " << n << "\n";
    for (int j = 0; j < UP; ++j){
        int fl = 0;
        int ch = n-pr[j];
        //cout << ch << "\n"; system("PAUSE");
        if (ch < 0) break;
        if (ch == 1) continue;
        if (ch > 1)
            for (int d = 0; d < MAXN; ++d)
                if (!(ch%pr[d])){
                    if (ch == pr[d])
                        break;
                    fl = 1;
                    break;
                }
        if (!fl || ch == 0){
            ans[i].PB(pr[j]);
            ans[i].PB(ch);
            return;
        }
    }
    for (int j = 0; j < UP; ++j)
        for (int k = 0; k < U; ++k){
            int fl = 0;
            int ch = n-pr[j]-pr[k];
            if (ch < 0) break;
            if (ch == 1) continue;
            if (ch > 1)
                    for (int d = 0; d < MAXN; ++d)
                    if (!(ch%pr[d])){
                        if (ch == pr[d])
                            break;
                        fl = 1;
                        break;
                    }
            if (!fl || ch == 0){
                ans[i].PB(pr[j]);
                ans[i].PB(pr[k]);
                ans[i].PB(ch);
                return;
            }
        }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> t;
    if (!t) { EX = 1; out(); return;}
    int ind = 0;
    for (int i = 2; i < (int)1e5; ++i)
        if (!mass[i]){
            pr[ind++] = i;
            mp[i] = 1;
            for (LL j = 1LL*i*i; j < (int)1e5; j += i)
                mass[j] = 1;
        }
    for (int i = 1; i <= t; ++i){
        cin >> n;
        solution(i);
    }
}

int main()
{
    in();
    out();
    return 0;
}
