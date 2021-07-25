#include <iostream>
#include <vector>

using namespace std;

const int MAS_SIZE = 1000+15;

int mass[MAX_SIZE][MAX_SIZE];

int n, m, k;

int main()
{
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        mass[x][y] = 1;
    }

}
