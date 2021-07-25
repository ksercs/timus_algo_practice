#include<iostream>

using namespace std;

long long x, y, ans, r;

int main()
{
    cin>>r;
    x = r;
    while(y<r)
    {
       while( x*x >= r*r-y*y && x >= 0 )--x;
       ans+=(x+1);
       y++;
    }
    ans*=4;
    cout << ans << "\n";
    return 0;
}
