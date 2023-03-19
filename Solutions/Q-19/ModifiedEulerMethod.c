// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 19. Write a C program for solving a differential equation D[y=Power[x,2]+y,x], y(0)=1.Find y(0.02) when h(0.01)=1 by Modified Euler's Method.


#include <stdio.h>
#include <math.h>

// Define the differential equation dy/dx = f(x, y)
double f(double x, double y) {
    return x*x + y;
}

int main() {
    double x0, y0, x, y, h;

    // Get the initial condition (x0, y0) from user input
    printf("Enter the initial condition (x0, y0): ");
    scanf("%lf %lf", &x0, &y0);

    // Get the step size h from user input
    printf("Enter the value of h: ");
    scanf("%lf", &h);

    x = x0;
    y = y0;
    while (x < 0.02) {
        // Compute the next value of y using the fourth-order Runge-Kutta method
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y = y + 0.5 * (k1 + k2);
        x = x + h;
    }

    // Output the final value of y
    printf("y(%lf) = %lf\n", x, y);

    return 0;
}

