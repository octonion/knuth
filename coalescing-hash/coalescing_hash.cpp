#include <iostream>
#include <map>
#include <bits/stdc++.h> // queue
#include <algorithm> // max

#include <quadmath.h>

using namespace std;

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

unsigned long int bound = 1000000000;
__float128 lb,x;

map<unsigned long int, unsigned int> runs;
map<unsigned long int, unsigned int>::iterator lower, upper;

int main() {

  cout << boolalpha;

  lb = logq(bound);

  // Assume values 1,2,3 already observed

  runs[1] = 2;

  queue<unsigned long int> queue;
  queue.push(3);

  while (!queue.empty()) {

    m = queue.front();
    queue.pop();
    
    x = lgammaq(m+1.0Q);

    if (x <= lb ) {
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

    upper = runs.upper_bound(n);
    lower = prev(upper);

    while (lower->first + lower->second < n) {
      queue.push(n);

      // Coalsece new value into previous cluster?

      if (n == lower->first + lower->second + 1) {
        runs[lower->first] += 1;
      } else {
        //cout << "Creating - " << n << endl;
        runs[n] = 0;
        lower++;
      }

      // Coalsece into next cluster?

      if (upper!=runs.end()) {
        if (n+1 == upper->first) {
          //cout << "Coalescing - " << lower->first << endl;
          runs[lower->first] += upper->second + 1;
          runs.erase(upper);
        }
      }

      n = isqrt(n);
      i += 1;

      upper = runs.upper_bound(n);
      lower = prev(upper);

    }
    
  }

  unsigned long int max_i = runs.begin()->first + runs.begin()->second;
  
  cout << max_i << endl;
  cout << runs.begin()->first << " => " << runs.begin()->second << endl;

  //cout << endl;
  //for (auto it = runs.begin(); it != runs.end(); it++)
  //  cout << (*it).first << " => " << (*it).second << endl;
  //cout << endl;

  return 0;

}
