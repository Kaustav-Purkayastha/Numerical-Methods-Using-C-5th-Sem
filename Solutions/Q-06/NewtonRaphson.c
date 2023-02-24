
// 6. Write a C program to find a real root of the equation Sin[x]=1+Cube[x] correct to 3 decimal places by using the Newton-Raphson Method.


#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
    return sin(x) - 1 - pow(x, 3);
}

double df(double x) {
    return cos(x) - 3 * pow(x, 2);
}

int main() {
    double x0, x1, f0, df0, error;

    // Input the initial guess
    printf("Enter the initial guess: ");
    scanf("%lf", &x0);

    do {
        // Calculate the function value and its derivative at the current guess
        f0 = f(x0);
        df0 = df(x0);

        // Calculate the next approximation using the Newton-Raphson formula
        x1 = x0 - f0 / df0;

        // Calculate the absolute error between the current and next approximation
        error = fabs(x1 - x0);

        // Update the current approximation
        x0 = x1;
    } while (error > EPSILON);

    // Print the root correct to 3 decimal places
    printf("The root is: %.3lf\n", x1);

    return 0;
}

