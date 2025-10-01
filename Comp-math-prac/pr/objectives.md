# newton raphson
# regula falsi
# gauss elimination
# gauss jacobi
# gauss seidel
# secant

# trapez
# simpson
# bisection
# newton for..., back..

# lagrange
# gauss jordan
# euler
# runge-kutta
// do
    // {
    //     printf("Iteration: %d\n", k++);
    //     printf("a = %f, b = %f\n", a, b);
    //     printf("f(a) = %f, f(b) = %f\n", f(a), f(b));

    //     h = (fabs(f(a)) * (b - a)) / (fabs(f(a)) + fabs(f(b)));
    //     // |f(x1)|*(x2-x1) / |x1| + |x2|
    //     xn = a + h;

    //     printf("h = %f, f(xn) = %f\n", h, f(xn));

    //     if (f(xn) < 0)
    //         a = xn;
    //     else
    //         b = xn;

    // } while (fabs(f(xn)) > error);


```sh
echo "Enter number of rows:"
read rows
echo "Enter number of columns:"
read cols

# Read matrix elements
echo "Enter elements of the matrix row by row:"
for ((i=0; i<rows; i++))
do
    for ((j=0; j<cols; j++))
    do
        read matrix[$i,$j]
    done
done

# Display input matrix
echo "Input Matrix:"
for ((i=0; i<rows; i++))
do
    for ((j=0; j<cols; j++))
    do
        echo -n "${matrix[$i,$j]} "
    done
    echo ""
done

# Transpose the matrix
for ((i=0; i<rows; i++))
do
    for ((j=0; j<cols; j++))
    do
        transpose[$j,$i]=${matrix[$i,$j]}
    done
done
```sh
