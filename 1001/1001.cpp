#include <iostream>

using namespace std;

int ans;

int main()
{
    int n, k;
    cin >> n >> k;
    ans=2*(n/k)+(n%k!=0)+((n%k>k/2.0)||(n<k));
    cout << 2*(n/k) << "\n";
    cout <<(n%k!=0) <<"\n";
    cout << ((n%k>k/2)||(n<k)) << "\n";
    //cout << ans << "\n";
    return 0;
}
