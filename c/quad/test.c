#include <stdio.h>
#include <quadmath.h>
#include <math.h>

#include "queue.h"
#include "uthash.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

unsigned long int p,q;
unsigned long int i,m,n;

unsigned long int bound = 1000000000000000;
__float128 lb,x,y;

int main() {

  lb = logq(bound);
  
  m = 41626;

  x = lgammaq(m+1.0Q);
  p = ceilq(log2q(x/lb));

  printf("p = %ld\n",p);
    
  i = 0;

  q = MAX(p,0);

  i += q;

  n = roundq(expq(x/powq(2,q)));

  printf("n = %ld\n",n);
    
  return 0;
}
