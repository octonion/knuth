#include <iostream>
#include "concurrentqueue.h" // concurrent queue
#include <algorithm> // max

#include <vector> // vector
#include <thread>
#include <math.h>
#include <quadmath.h>

using namespace std;

//const unsigned long int bound = 18446744073709551615;
const unsigned long int bound = 1000000000000000;
//const long int bits = 1099511627776;
//const long int bits = 1000000000;
const int nthreads = 4;
const long int bits = 4294967296;
//const long int bits = 68719476736;

unsigned long int fsqrt(unsigned long int x) {
  unsigned long int y = sqrt(x) - 0x1p-20;
  if (2*y < x - y*y)
    ++y;
  return y;
}

__float128 lb = logq(bound);

moodycamel::ConcurrentQueue<unsigned long int> queue;

vector<bool> found (bits);

int task(int k) {

  unsigned int p;
  unsigned long int m,n;
  __float128 x;
  
  while (queue.try_dequeue(m)) {

    x = lgammaq(m+1.0Q);

    if (x < lb ) {
      p = 0;
    } else {
      p = ceilq(log2q(x/lb));
    }
    
    if (p==0) {
      n = roundq(expq(x/powq(2,p)));
    } else {
      n = floorq(expq(x/powq(2,p)));
    }

    while ( (n>=bits) || (n<bits && !found[n]) ) {
      if (n<bits) {
        queue.enqueue(n);
        found[n] = true;
        n = fsqrt(n);
      } else {
        queue.enqueue(n);
        n = fsqrt(n);
      }
          
    }
    
  }

  return 0;

}

int main() {

  thread threads[nthreads];

  found[3] = true;
  
  queue.enqueue(3);

  for (auto i=0; i<nthreads; i++) {
    threads[i] = thread(task, i);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  for (auto i=0; i<nthreads; i++) {
    threads[i].join();
  }

  unsigned long int max_i = 1;

  while (found[max_i]) {
    max_i += 1;
  }

  unsigned long int v;
  
  cout << max_i << endl;

  return 0;

}
