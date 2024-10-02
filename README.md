# Implementing Chinese Remainder Theorem

## I/O
- Input: 
  - `n`: number of input
  - `divisor[i]`: i-th divisor
  - `remainder[i]`: i-th remainder
- output:
  - generic term for the solution

## Logic flow (normal)
1. Receives number of equations, and initialize arrays accordingly.
2. Receives divisors / remainders.
   - compute LCM of all divisors alongside
   - as we assume all divisors to be pairwise coprime, we simply multiply them. 
3. Compute solution: for each equation, repeat:
   - compute $x$: product of all divisors except current one
   - find multiplicative inverse of $x$ in mod divisor
   - when inverse is found, add 
     - `remainder * x * multiplicative_inverse`
     - to total solution
4. Prints total solution

## Logic flow (extended)
1. Receives number of equations, and initialize arrays accordingly.
2. Receives coefficients / divisors / remainders.
   - preprocess them: divide entire equation by GCD OR multiply MMI of coefficient
   - compute LCM of all divisors alongside
   - as we assume all divisors to be pairwise coprime, we simply multiply them. 
3. Compute solution: for each equation, repeat:
   - compute $x$: product of all divisors except current one
   - find multiplicative inverse of $x$ in mod divisor
   - when inverse is found, add 
     - `remainder * x * multiplicative_inverse`
     - to total solution
4. Prints total solution

### Compilation

Compiled with:
```powershell
g++ -std=c++11 crt.cpp -o crt -lgmpxx -lgmp
g++ -std=c++11 crt_ext.cpp -o crt_ext -lgmpxx -lgmp
```