#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double v,a,k,len;

int main()
{
  cin>>v>>a>>k;
  a=a*3.1415926535/180;
  while (v> 0.0001)
  {
    len=len+v*v*sin(2*a)/10;
    v=v/sqrt(k);
  }
  cout << fixed << setprecision (2) << len << "\n";
  return 0;
}
