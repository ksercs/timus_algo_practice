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

const int MAXN = 1000 + 15;

int n, len, mod, S;
int dp[MAXN], sum[MAXN];
VEC <string> ans;
string str;

void sol1 ()
{
    if ( !(S % mod ) ){
        ans.PB(str.substr(1));
        return;
    }
    for (int i = 1; i < len; ++i)
        if (str[i]){
            if ( !( (S-i) % mod ) ){
                str[i] = '0';
                ans.PB(str.substr(1));
                return;
            }
        }
        /*else{
            if ( !( (dp[len]+i) % mod ) ){
                str[i] = '1';
                ans.PB(str.substr(1));
                return;
            }
        }*/
}

void sol2()
{
    //cout << S << "\n";
    if ( !( (S+len) % mod) ){
        str += '1';
        ans.PB(str.substr(1));
        return;
    }
    if ( !( (S) % mod) ){
        str += '0';
        ans.PB(str.substr(1));
        return;
    }
    for (int i = 1; i < len; ++i){
        if ( !( (S + sum[len-1] - sum[i-1]) % mod ) ){
            str = str.substr(1,i-1) + '0' + str.substr(i, len-i);
            ans.PB(str);
            return;
        }
        if ( !( (S + sum[len-1] - sum[i-1] + i) % mod ) ){
            str = str.substr(1,i-1) + '1' + str.substr(i, len-i);
            ans.PB(str);
            return;
        }
    }

}

void sol3()
{
    for (int i = 1; i < len; ++i){
        if ( !( (S - sum[len-1] + sum[i] - int(str[i]-'0')*i) % mod ) ){
            str = str.substr(1,i-1) + str.substr(i+1, len-i-1);
            ans.PB(str);
            return;
        }
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    mod = n+1;
    getline(cin, str);
    while (getline(cin, str)){
        for (int i = 0; i < str.SZ; ++i)
            if (str[i] == ' '){
                str = str.substr(0, i) + str.substr(i+1, (int)str.SZ-i-1);
            }
        //cout << str << "\n";
        str = '0'+str;
        len = int(str.SZ);
        for (int i = 1; i < len; ++i){
            dp[i] = dp[i-1] + (int)(str[i]-'0')*i;
            sum[i] = sum[i-1] + (int)(str[i]-'0');
        }
        /*for (int i = 1; i <= str.SZ; ++i)
            cout << dp[i];
        cout << "\n";*/
        S = dp[len-1];
        if (len-1 == n)
            sol1();
        if (len-1 == n-1)
            sol2();
        if (len-1 == n+1)
            sol3();
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
