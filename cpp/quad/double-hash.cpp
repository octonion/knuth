#include <iostream>
#include <bits/stdc++.h> // queue
#include <algorithm> // max
#include <bitset>
#include <vector>

#include <set>

#include <quadmath.h>

using namespace std;

const long int bits = 1000000000;

// From Rosetta Code

unsigned long int isqrt(unsigned long int x) {
  unsigned long int q = 1, r = 0;
  while (q <= x) {
    q <<= 2;
  }
  while (q > 1) {
    long int t;
    q >>= 2;
    t = x - r - q;
    r >>= 1;
    if (t >= 0) {
      x = t;
      r += q;
    }
  }
  return r;
}

unsigned int i,p;
unsigned long int m,n;

unsigned long int bound = 1000000000000;
__float128 lb,x;

int main() {

  std::vector<std::bitset<bits>> wrapper(1);
  auto & found = wrapper[0];

  unordered_set<unsigned long int> big_found;

  lb = logq(bound);

  found[3] = true;
  
  queue<unsigned long int> queue;
  queue.push(3);

  while (!queue.empty()) {

    m = queue.front();
    queue.pop();
    x = lgammaq(m+1.0Q);

    if (x < lb ) {
      p = 0;
    } else {
      p = ceilq(log2q(x/lb));
    }
    
    i = p;

    if (p==0) {
      n = roundq(expq(x/powq(2,p)));
    } else {
      n = floorq(expq(x/powq(2,p)));
    }

    while ( (n<bits && !found[n]) ||
            (n>=bits && (big_found.find(n) == big_found.end())) ) {
      if (n<bits) {
        queue.push(n);
        found[n] = true;
        n = isqrt(n);
        i += 1;
      } else {
        queue.push(n);
        big_found.insert(n);
        n = isqrt(n);
        i += 1;
      }
    }
  }

  unsigned long int max_i = 1;

  while (found[max_i]) {
    max_i += 1;
  }

  unsigned long int v;
  
  cout << max_i << endl;

  return 0;

}
