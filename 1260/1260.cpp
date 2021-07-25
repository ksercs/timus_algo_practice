#include <iostream>

using namespace std;

int n;

int mass[60];

int get_ans(int ch)
{
  if (mass[ch] != 0) return mass[ch];
  else return mass[ch]=get_ans(ch-1)+get_ans(ch-3)+1;
} 

int main()
{
  cin >> n;
  mass[1] =1;
  mass[2] = 1;
  mass[3] = 2;
  cout << get_ans(n);
}