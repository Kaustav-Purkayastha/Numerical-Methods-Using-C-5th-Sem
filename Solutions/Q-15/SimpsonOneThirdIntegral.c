// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 15. Write a C program to evaluate  Integrate[Divide[x,1+Square[x]],{x,0,1}]  using Simpson's One-Third Rule.


#include <stdio.h>
#include <math.h>

double f(double x) {
    return x / (1 + x * x);
}

double simpson(double a, double b, int n) {
    double h = (b - a) / n;  // calculate the width of each subinterval
    double x, sum = 0.0;
    int i;
    // evaluate the integral using Simpson's one-third rule
    for (i = 0; i <= n; i++) {
        x = a + i * h;
        if (i == 0 || i == n) {
            sum += f(x);
        } else if (i % 2 == 1) {
            sum += 4 * f(x);
        } else {
            sum += 2 * f(x);
        }
    }
    return sum * h / 3.0;
}

int main() {
    double a, b;
    int n;
    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (must be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: number of subintervals must be even.\n");
        return 1;
    }

    double integral = simpson(a, b, n);
    printf("The definite integral of f(x) = x / (1 + x^2) from %g to %g using Simpson's one-third rule with %d subintervals is: %g\n", a, b, n, integral);

    return 0;
}

