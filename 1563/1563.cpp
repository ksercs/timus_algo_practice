#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, ans;

string str;

map <string, int> mp;

int main()
{
    cin >> n; getline(cin, str);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, str);
        if (mp[str]) ans++;
        mp[str]=1;
    }
    cout << ans << "\n";
    return 0;
}
