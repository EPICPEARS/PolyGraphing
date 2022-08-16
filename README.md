# PolyGraphing
 PolyGraphing is a way to experiment quickly from the command line with polynominal functions

## Usage

### Build
```
make
```

### Run 

```
./bin/out <polynomial degree> <coefficient of term 1> <coefficient of term 2> ... <coefficient of term n>
```

All Polynominals to be graphed are first in standard form. Then the Coefficients are taken

Example 1:

For the polynomial in standard form:
```
f(x) = x^2 - 6x - 16
```

The command to graph ```y = f(x)``` is:

```
./bin/out 2 1 -6 -16
```

Example 2:
```
g(x) = x^3 - 3x^2 - x + 3
```

The command to graph ```y = g(x)``` is:

```
./bin/out 3 1 -3 -1 3
```



