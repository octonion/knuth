#include <stdio.h>
#include <quadmath.h>
#include <math.h>

#include "queue.h"
#include "uthash.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#include <stdint.h>
 
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
 
typedef struct node
{
    unsigned long int value;
    TAILQ_ENTRY(node) nodes;
}snode;

typedef struct triplet {
  unsigned long int key;
  unsigned long int next;
  unsigned int sqrts;
  UT_hash_handle hh;
}striplet;

striplet *paths = NULL;

void add_triplet(striplet **dict, unsigned long int id, unsigned long int n, unsigned int sr) {
  
  striplet *s;
  HASH_FIND_ULINT(*dict, &id, s);
  if (s == NULL) {
    s = (striplet*)malloc(sizeof *s);
    s->key = id;
    s->next = n;
    s->sqrts = sr;
    HASH_ADD_ULINT(*dict, key, s);
  }
  
}

unsigned long int p,q;
unsigned long int i,m,nn;

unsigned long int bound = 1000000000;
__float128 lb,x,y;

int main() {

  lb = logq(bound);
  
  striplet *s;
  s = (striplet*)malloc(sizeof *s);

  add_triplet(&paths, 3, 3, 0);

  TAILQ_HEAD(head_s, node) head;
  TAILQ_INIT(&head);

  snode *e = NULL;

  e = malloc(sizeof(struct node));
  e->value = 3;
  TAILQ_INSERT_TAIL(&head, e, nodes);
  e = NULL;

  while (!TAILQ_EMPTY(&head)) {

    e = TAILQ_FIRST(&head);
    m = e->value;

    TAILQ_REMOVE(&head, e, nodes);
    free(e);
    e = NULL;

    x = lgammaq(m+1.0Q);

    if (x <= lb ) {
      p = 0;
    } else {
      p = ceill(log2q(x/lb));
    }
    
    i = 0;

    q = MAX(p,0);

    i += q;

    if (q==0) {
      nn = roundq(expq(x/powq(2,q)));
    } else {
      nn = floorq(expq(x/powq(2,q)));
    }
      
    while (nn>3) {
      
      HASH_FIND_ULINT(paths, &nn, s);
      if (s == NULL) {
        e = malloc(sizeof(struct node));
        e->value = nn;
        TAILQ_INSERT_TAIL(&head, e, nodes);
        e = NULL;

        add_triplet(&paths, nn, m, i);
      }

      nn = isqrt(nn);
      i += 1;
    }
  }

  unsigned long int max_i = 3;
  HASH_FIND_ULINT(paths, &max_i, s);
  while (s != NULL) {
    max_i += 1;
    HASH_FIND_ULINT(paths, &max_i, s);
  }

  unsigned long int v,w;
  
  v = 3;
  while (v<max_i) {
      HASH_FIND_ULINT(paths, &v, s);
      w = s->next;
      printf("%lu,%lu,%d\n", v, w, s->sqrts);
      v += 1;
  }

  return 0;
}
