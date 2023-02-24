
// 5. Write a C program to find a real root of the equation Square[x]-Sin[x]-9=0 by using the Bisection Method.


#include <stdio.h>
#include <math.h>

// Define the function to find the root of
double f(double x) {
    return x * x - sin(x) - 9;
}

int main() {
    double a, b, c, eps;
    int nmax, n;

    // Read in the interval [a, b], the tolerance eps, and the maximum number of iterations nmax
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance eps: ");
    scanf("%lf", &eps);
    printf("Enter the maximum number of iterations nmax: ");
    scanf("%d", &nmax);

    // Check if f(a) and f(b) have opposite signs
    if (f(a) * f(b) >= 0) {
        printf("Error: f(a) and f(b) do not have opposite signs\n");
        return 1;
    }

    // Bisection Method
    n = 0;
    while (n < nmax) {
        c = (a + b) / 2;
        if (fabs(f(c)) < eps) {
            // Root found!
            printf("Found root: x = %lf\n", c);
            return 0;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        n++;
    }

    // Maximum number of iterations reached
    printf("Error: maximum number of iterations reached\n");
    return 1;
}

