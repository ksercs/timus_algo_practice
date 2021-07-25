#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1e5+15;

int n, m, nmax, mmax, nst, nfn, mst, mfn, nbmin, mbmin, fast1, fast2;

void in()
{
    //ifstream cin("2069.in");
    cin >> n >> m;
    cin >> nst;
    for (int i = 1; i < n-1; i++)
    {
        int ch;
        cin >> ch;
        nmax = max(nmax, ch);
    }
    cin >> nfn;
    nmax = max(nmax, nst);
    nmax = max(nmax, nfn);
    nbmin = min(nst, nfn);
    cin >> mst;
    for (int i = 1; i < m-1; i++)
    {
        int ch;
        cin >> ch;
        mmax = max(mmax, ch);
    }
    cin >> mfn;
    mmax = max(mmax, mst);
    mmax = max(mmax, mfn);
    mbmin = min(mst, mfn);
    fast1 = min(nst, mfn);
    fast2 = min(mst, nfn);
}

void out()
{
   // ofstream cout("2069.out");
    cout << max(max(fast1, fast2), max(min(nbmin, mmax), min(mbmin, nmax))) << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
