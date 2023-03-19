// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 17. Write a C program for solving a differential equation D[y=3x+Divide[y,2],x] and y(0)=1. Find the values of y(0,1) and y(0,2) by using the Taylor Series Method.


#include <stdio.h>
#include <math.h>

// function to calculate the value of f(x, y)
double f(double x, double y) {
    return 3 * x + y / 2;
}

int main() {
    double x0, y0, h, x, y, k1, k2, k3, k4;
    int n, i;

    // get initial values and step size from user
    printf("Enter the initial value of x: ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y: ");
    scanf("%lf", &y0);
    printf("Enter the step size: ");
    scanf("%lf", &h);
    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // print the initial values
    printf("x0 = %lf, y0 = %lf\n", x0, y0);

    // perform n iterations of the method
    for (i = 1; i <= n; i++) {
        x = x0 + i * h;
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);
        y = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // print the values of x and y
        printf("x%d = %lf, y%d = %lf\n", i, x, i, y);

        // update x0 and y0
        x0 = x;
        y0 = y;
    }

    // print the final value of y
    printf("The value of y(0, %d) is %lf\n", n, y);

    return 0;
}

