#include <iostream>
#include <vector>

using namespace std;

int n, del, ost, sum;

vector <int> vec;

int mass[6];

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ch;
        cin >> ch;
        vec.push_back(ch);
        mass[ch]=1;
        sum += ch;
    }
}

void solution()
{
    del = sum/n;
    ost = sum%n;
}

void out()
{
    if (!mass[3] && !mass[4]) cout <<"Named\n";
    else
    {
        if (!mass[3] && (del == 5 || (del == 4 && ost >= n/2+(n%2)))) cout << "High\n";
        else
        {
            if (!mass[3]) cout <<"Common\n";
            else          cout <<"None\n";
        }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
