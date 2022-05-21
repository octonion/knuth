## Knuth's Conjecture

Using only the operations of $!$ (factorial), $\sqrt{}$ and $\lfloor \rfloor$, can you construct any positive integer starting with a 3?

For example, $5 = \lfloor{\sqrt{\sqrt{(3!)!}}}\rfloor$.

# Compiling and running

```
sage check.sage quad_15.txt
```

```
julia log_gamma.jl
```

```
gcc log_gamma_ldouble.c -lm
./a.out
```

```
icc log_gamma_ldouble.c -lm
./a.out
```

```
gcc log_gamma_quad.c -lquadmath
./a.out
```

```
icc log_gamma_quad.c -lquadmath
./a.out
```
