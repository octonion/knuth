# Knuth's Conjecture

Using only the operations of $x!$, $\sqrt{x}$ and $\lfloor{x}\rfloor$, can you construct any positive integer starting with a 3?

For example, $5 = \left\lfloor{\sqrt{\sqrt{(3!)!}}}\right\rfloor$.

## Compiling and running

### C++, g++, long double floats

```
g++ -O3 double-hash.cpp
./a.out
```

### C++, icc, long double floats

```
icc -O3 double-hash.cpp
./a.out
```

### C++, g++, quad-precision floats using quadmath library

```
g++ -O3 double-hash.cpp -lquadmath
./a.out
```

### C++, icc, quad-precision floats using quadmath library

```
icc -O3 double-hash.cpp -lquadmath
./a.out
```
