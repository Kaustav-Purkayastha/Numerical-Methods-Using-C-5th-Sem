// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 20. Write a C program to approximate y when x=0.1, 0.2, 0.3 and h=0.1 using Runge-Kutta Method. Given x=0, when y=1 and D[y,x]=x+y.


#include <stdio.h>

// define the differential equation
double f(double x, double y) {
    return x + y;
}

int main() {
    double x0 = 0, y0 = 1, x, y, k1, k2, k3, k4, h;
    int i;

    // get the step size from user
    printf("Enter the step size h: ");
    scanf("%lf", &h);

    // loop through three iterations
    for (i = 1; i <= 3; i++) {
        // calculate the values of k1, k2, k3, and k4
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h/2, y0 + k1/2);
        k3 = h * f(x0 + h/2, y0 + k2/2);
        k4 = h * f(x0 + h, y0 + k3);

        // calculate the value of y and increment x0 and y0
        y = y0 + (k1 + 2*k2 + 2*k3 + k4)/6;
        x = x0 + h;

        // print the value of y
        printf("y(%0.1f) = %0.6f\n", x, y);

        x0 = x;
        y0 = y;
    }

    return 0;
}

