# Knuth's Conjecture

Using only the operations of $x!$, $\sqrt{x}$ and $\lfloor{x}\rfloor$, can you construct any positive integer starting with a 3?

For example, $5 = \left\lfloor{\sqrt{\sqrt{(3!)!}}}\right\rfloor$.

## Compiling and running

### SageMath

```
sage check.sage quad_15.txt
```

### Julia

```
julia log_gamma.jl
```

### gcc, long double floats

```
gcc log_gamma_ldouble.c -lm
./a.out
```

### icc, long double floats

```
icc log_gamma_ldouble.c -lm
./a.out
```

### gcc, quad-precision floats using quadmath library

```
gcc log_gamma_quad.c -lquadmath
./a.out
```

### icc, quad-precision floats using quadmath library

```
icc log_gamma_quad.c -lquadmath
./a.out
```
