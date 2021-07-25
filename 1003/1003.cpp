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

map<int, bool>  exist, odd;
map<int, int>  previous;

VEC <int> ans;

bool add(int a, int b,  bool c){//b>=a;
    cout << a << " " << b << " " << c << "\n";
    if (!exist[b]){
      exist[b] = true;
      odd[b] = c;
      previous[b] = a;
      return true;
    };
    int  i = previous[b];
    if (i == a) return (odd[b]==c);
    if (i < a)  return add(i, a-1, (c!=odd[b]));
    return add(a, i-1, (c!=odd[b]));
};

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    while (1) {
        exist.clear();
        odd.clear();
        previous.clear();
        int numbers = 0;
        cin >> numbers;
        if (numbers ==-1 ) break;
        int questions = 0;
        cin >> questions;
        bool flag = false;
        for (int i = 0; i < questions; i++) {
            int a = 0;
            cin >> a;
            int b = 0;
            cin >> b;
            string tmp;
            cin >> tmp;
            bool parity = 1;
            if (tmp=="even")
                parity = 0;
            if ( (!add(a,b,parity)) && (!flag)) {
                ans.PB(i);
                flag=true;
            //break;
            }
        }
        if (flag==false) {
            //cout << questions;
            ans.PB(questions);
        }
    }
    for (int i = 0;  i < ans.SZ; ++i)
        cout << ans[i] << "\n";
    return 0;
}
