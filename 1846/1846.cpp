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

const int MAXN = (1<<18) + 15, firstL = (1<<17);

int q;
int tr[MAXN], Lcnt = 1;
map <int, VEC <int> > mp;

int gcd_R(int a, int b)
{
    return ( (a&&b) ? gcd_R(b, a%b) : (a|b)  );
}


void upd (int ind)
{
    tr[ind] = gcd_R(tr[ind*2], tr[ind*2+1]);
    //cout << ind << " " << tr[ind] << "\n";
    if (ind > 1) upd(ind/2);
}

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin >> q;
    //cout << firstL << "\n";
    for (int i = 0; i < q; ++i){
        char t;
        int num;
        cin >> t >> num;
        if (t == '+'){
            int new_pos = firstL + Lcnt;
            //cout << "NEW_POS = " << new_pos << "\n";
            mp[num].PB(new_pos);
            tr[new_pos] = num;
            ++Lcnt;
            upd(new_pos/2);
        }
        else{
            int ind = mp[num][0];
            mp[num].erase(mp[num].begin());
            //cout << "IND = " << ind << "\n";
            tr[ind] = 0;
            upd(ind/2);
        }
        cout << max(tr[1], 1) << "\n";
    }
    return 0;
}
