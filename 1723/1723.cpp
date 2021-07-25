#include <iostream>
#include <string>

using namespace std;

string str;

int maxi;
int c[256];

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        c[str[i]-'a']++;
    }
    for(int i = 0; i < 256; i++)
    {
        if (c[i] > c[maxi]) maxi = i;
    }
    cout << char(maxi+'a') << "\n";
}
