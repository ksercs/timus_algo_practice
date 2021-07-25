#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

priority_queue <unsigned int> q;
unsigned int n, a, top1, top2;

int main()
{
  scanf("%u", &n);
  for (unsigned int i = 1; i <= n/2+1; ++i)
  {
      scanf("%u", &a);
    q.push(a);
  }
  for (unsigned int i = n/2+2; i <= n; ++i)
  {
   scanf("%u", &a);
   q.push(a);
   q.pop();
  }
  top1 = q.top();
  q.pop();
  top2 = q.top();
  if (n%2 == 1) printf("%u\n", top2);
  else
  {
        if ((top1+top2)%2==0) printf("%u.0\n", top1/2+top2/2+top1%2);
        else                  printf("%u.5\n", top1/2+top2/2);
  }
}
