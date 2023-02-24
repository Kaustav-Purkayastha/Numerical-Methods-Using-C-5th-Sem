
// 4. Write a C program to find the real root of the equation Cube[x]-4x+1=0  by using the Method of Successive Approximation.


#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001 // the desired accuracy

// the function f(x) = x^3 - 4x + 1
double f(double x) {
    return pow(x, 3) - 4 * x + 1;
}

// the function g(x) = (x^3 + 1) / 4
double g(double x) {
    return (pow(x, 3) + 1) / 4;
}

int main() {
    double x0, x1, error;

    // take the initial approximation x[0] as input from the user
    printf("Enter the initial approximation x[0]: ");
    scanf("%lf", &x0);

    do {
        x1 = g(x0); // apply the iterative formula
        error = fabs(x1 - x0); // calculate the error
        x0 = x1; // update x[0] for the next iteration
    } while (error >= EPSILON);

    // print the root and the error
    printf("The real root of the equation is: %lf\n", x1);
    printf("The error is: %lf\n", error);

    return 0;
}

