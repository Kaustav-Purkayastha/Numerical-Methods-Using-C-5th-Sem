
// 16. Write a C program to evaluate  Integrate[Sqrt[1-8Power[x,3]],{x,0,0.3}]  using Simpson's Three-Eight Rule.


#include <stdio.h>
#include <math.h>

double func(double x) {
    return sqrt(1 - 8 * pow(x, 3));
}

int main() {
    double a, b;
    int n, i;
    double h, sum;
    double x0, x1, x2, x3;

    printf("Enter the lower limit: ");
    scanf("%lf", &a);

    printf("Enter the upper limit: ");
    scanf("%lf", &b);

    printf("Enter the number of sub-intervals (must be a multiple of 3): ");
    scanf("%d", &n);

    // Calculate the width of each sub-interval
    h = (b - a) / n;

    // Initialize the sum to the value of the function at the end-points
    sum = func(a) + func(b);

    // Loop to sum up the values of the function at the interior points
    for (i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * func(x);
        } else {
            sum += 3 * func(x);
        }
    }

    // Calculate the final result
    double result = 3 * h / 8 * sum;
    printf("The approximate value of the integral is: %lf\n", result);

    return 0;
}

