# Knuth's Conjecture

Using only the operations of $x!$, $\sqrt{x}$ and $\lfloor{x}\rfloor$, can you construct any positive integer starting with a 3?

For example, $5 = \left\lfloor{\sqrt{\sqrt{(3!)!}}}\right\rfloor$.

## Compiling and running

### C++, g++, multithreaded, concurrent queue, quad-precision floats using quadmath library

```
g++ -O3 quad.cpp -lquadmath -lpthread
./a.out
```

### C++, icc, multithreaded, concurrent queue, quad-precision floats using quadmath library

```
icc -O3 quad.cpp -lquadmath -lpthread
./a.out
```
